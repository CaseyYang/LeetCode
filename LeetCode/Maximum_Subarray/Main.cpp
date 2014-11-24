#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (n == 0) return 0;
		vector<int> dp = vector<int>(n);
		dp[0] = A[0];
		int maxSum = A[0];
		for (int i = 1; i < n; ++i){
			dp[i] = max(dp[i - 1] + A[i], A[i]);
			if (dp[i]>maxSum) maxSum = dp[i];
		}
		return maxSum;
	}
};
int main(){
	return 0;
}