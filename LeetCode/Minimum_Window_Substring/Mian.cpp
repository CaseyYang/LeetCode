#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
using namespace std;
class Solution {
public:
	bool compare(map<char, int> &m1, map<char, int> &m2){
		for (map<char, int>::iterator iter = m1.begin(); iter != m1.end(); ++iter){
			if (m2[iter->first] != iter->second){
				return false;
			}
		}
		return true;
	}
	string minWindow(string S, string T) {
		map<char, int> words = map<char, int>();
		map<char, int> foundWords = map<char, int>();
		queue<int> indexes = queue<int>();
		for (int i = 0; i < T.size(); ++i){
			words[T[i]] += 1;
		}
		int j = -1;
		char curWord;
		int minLength = INT_MAX;
		int start = 0;
		for (int i = 0; i < S.size(); ++i){
			if (words[S[i]] > 0){
				if (!compare(words, foundWords)){
					foundWords[S[i]] += 1;
					indexes.push(i);
				}
				else{
					while (true){
						j = indexes.front();
						indexes.pop();
						int curLength = i - j;
						if (curLength < minLength){
							minLength = curLength;
							start = j;
						}
						curWord = S[j];
						foundWords[curWord] -= 1;
						if (foundWords[curWord] < words[curWord]){
						}
					}
				}
			}
		}
		if (minLength < INT_MAX){
			return S.substr(start, minLength);
		}
		else{
			return "";
		}
	}
};
int main(){
	string S = "ADOBECODEBANC", T = "ABC";
	Solution ss;
	cout << ss.minWindow(S, T) << endl;
	return 0;
}