#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
struct Node{
	map<char, int> ms;
	Node(){
		ms = map<char, int>();
	}
	Node(const Node &source) :ms(source.ms){}
	void output(){
		for each (pair<char, int> var in ms)
		{
			cout << var.first << "," << var.second << " ";
		}
		cout << "#";
	}
};
class Solution {
public:
	string minWindow(string S, string T) {
		if (T.size() == 0) return "";
		int minLength = INT_MAX;
		int start = 0;
		Node *dp = new Node[S.size()];
		for (int i = 0; i < S.size(); ++i){
			for (int j = i; j < S.size(); ++j){
				if (i == 0){
					if (j != 0)	dp[j] = Node(dp[j - 1]);
					if (T.find_first_of(S[j]) != T.npos){
						dp[j].ms[S[j]] += 1;
					}
				}
				else{
					if (T.find_first_of(S[i - 1]) != T.npos){
						dp[j].ms[S[i - 1]] -= 1;
					}
				}
				int flag = true;
				for (int k = 0; k < T.size(); ++k){
					if (dp[j].ms[T[k]] != 1){
						flag = false;
						break;
					}
				}
				if (flag&&minLength>j - i + 1){
					minLength = j - i + 1;
					start = i;
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