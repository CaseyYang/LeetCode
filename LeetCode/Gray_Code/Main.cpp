#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void recursion(vector<int> &result, int curMax, int n, int cur, int pre){
		result.push_back(cur);
		cout << cur << endl;
		if (curMax == n - 1) return;
		for (int i = 0; i < n; ++i){
			int tmp = cur ^ (1 << i);
			if (tmp != pre){
				recursion(result, i, n, tmp, cur);
			}
		}
	}
	vector<int> grayCode(int n) {
		vector<int> result;
		if (n == 0){
			result.push_back(0);
			return result;
		}
		else{
			if (n == 1){
				result.push_back(0);
				result.push_back(1);
				return result;
			}
			else{
				recursion(result, 0, n, 0, -1);
				return result;
			}
		}
	}
};

int main(){
	Solution s;
	s.grayCode(3);
	return 0;
}