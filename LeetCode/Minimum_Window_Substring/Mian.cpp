#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct Node{
	map<char, int> ms;
	Node(){
		ms = map<char, int>();
	}
};
class Solution {
public:
	string minWindow(string S, string T) {
		if (T.size() == 0) return "";
		Node *dp = new Node[S.size()];
		for (int i = 0; i < S.size(); ++i){
			for (int j = i; j < S.size(); ++j){
				dp[i]
			}
		}
	}
};
int main(){
	return 0;
}