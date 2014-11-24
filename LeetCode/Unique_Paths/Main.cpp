#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> dp = vector<int>(n);
		for (int i = 0; i < n; ++i){
			dp[i] = 1;
		}
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				dp[j] += dp[j - 1];
			}
		}
		return dp[n - 1];
	}
};
int main(){
	Solution s;
	cout<<s.uniquePaths(2, 2)<<endl;
	return 0;
}