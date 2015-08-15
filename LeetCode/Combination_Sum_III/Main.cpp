#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> result;
	void rec(vector<int> &tmpResult, int start, int k, int n){
		if (k == 0 && n == 0){
			result.push_back(tmpResult);
			return;
		}
		for (int i = start + 1; i <= 9; ++i){
			if (i <= n){
				tmpResult.push_back(i);
				rec(tmpResult, i, k - 1, n-i);
				tmpResult.pop_back();
			}
			else{
				return;
			}
		}
	}
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> tmpResult = vector<int>();
		rec(tmpResult, 0, k, n);
		return result;
	}
};

void main(){
	Solution s;
	s.combinationSum3(4, 54);
}