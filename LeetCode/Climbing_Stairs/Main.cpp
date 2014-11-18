#include<iostream>
using namespace std;
class Solution {
public:
	int climbStairs(int n) {
		if (n == 0 || n == 1) return n;
		int *dp = new int[n];
		dp[0] = 1;
		dp[1] = 2;
		for (int i = 2; i < n; ++i){
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n-1];
	}
};
int main(){
	int n = 38;
	Solution s;
	cout<<s.climbStairs(n)<<endl;
	return 0;
}