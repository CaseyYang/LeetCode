#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> results;
	void DFS(string &result, int m, int n){
		if (m == n&&n == 0) results.push_back(result);
		else{
			if (m > 0) DFS(result + '(', m - 1, n);
			if (m < n&&n>0) DFS(result + ')', m, n - 1);
		}
	}
	vector<string> generateParenthesis(int n) {
		string result = "";
		DFS(result, n, n);
		return results;
	}
};
int main(){
	return 0;
}