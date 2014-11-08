#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void OutputD(int *D,int l){
	for (int i = 0; i < l; ++i){
		cout << D[i] << " ";
	}
	cout << endl;
}

void OutputP(bool **P, int l){
	for (int i = 0; i < l; ++i){
		for (int j = 0; j < l; ++j){
			cout << P[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		int *D = new int[len + 1];
		bool **P = new bool*[len];
		for (int i = 0; i < len; ++i){
			P[i] = new bool[len];
		}
		for (int i = 0; i <= len; i++){
			D[i] = len - i;
		}
		for (int i = 0; i < len; i++){
			for (int j = 0; j < len; j++){
				P[i][j] = false;
			}
		}
		for (int i = len - 1; i >= 0; i--){
			for (int j = i; j < len; j++){
				if (s[i] == s[j] && (j - i < 2 || P[i + 1][j - 1])){
					P[i][j] = true;
					D[i] = min(D[i], D[j + 1] + 1);
				}
			}
		}
		OutputD(D, len + 1);
		cout << endl;
		OutputP(P, len);
		return D[0] - 1;
	}

	int minCut2(string s) {
		int n = s.size();
		vector<int> cut(n + 1, 0);  // number of cuts for the first k characters
		for (int i = 0; i <= n; i++) cut[i] = i - 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) // odd length palindrome
				cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);

			for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++) // even length palindrome
				cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
		}
		return cut[n];
	}
};

int main(){
	string ss = "abbacabbacd";
	Solution s;
	s.minCut(ss);
	return 0;
}