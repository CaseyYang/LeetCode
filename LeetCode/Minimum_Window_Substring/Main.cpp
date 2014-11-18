#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
	string minWindow(string S, string T) {
		int start = 0;
		int minStart = 0;
		int minLength = INT_MAX;
		int tWordsCount[256] = { 0 };
		int curWordsCount[256] = { 0 };
		queue<int> indexes = queue<int>();
		for (int i = 0; i < T.size(); ++i){
			tWordsCount[T[i]] += 1;
		}
		int i = 0;
		int total = 0;
		for (; i < S.size(); ++i){
			//cout << "Íâ²ã£º" << start << " " << minLength << endl;
			if (tWordsCount[S[i]] > 0){
				if (curWordsCount[S[i]] < tWordsCount[S[i]]){
					++total;
				}
				++curWordsCount[S[i]];
				indexes.push(i);
				if (total == T.size()){
					while (total == T.size()){
						//cout << "ÄÚ²ã£º" << start << " " << minLength << endl;
						start = indexes.front();
						indexes.pop();
						if (minLength > i - start + 1){
							minLength = i - start + 1;
							minStart = start;
						}
						char curWord = S[start];
						//cout << S.substr(start, minLength) << endl;
						--curWordsCount[curWord];
						if (curWordsCount[curWord] < tWordsCount[curWord]){
							--total;
						}
					}
				}
			}
		}
		if (total == T.size() || minLength < INT_MAX){
			if (minLength < INT_MAX)
				return S.substr(minStart, minLength);
			else
				return S.substr(indexes.front());
		}
		else{
			return "";
		}
	}
};
int main(){
	//string S = "ADOBECODEBANC", T = "ABC";
	//string S = "a", T = "a";
	//string S = "bdab", T = "ab";
	string S = "cabwefgewcwaefgcf", T = "cae";
	Solution ss;
	cout << ss.minWindow(S, T) << endl;
	return 0;
}