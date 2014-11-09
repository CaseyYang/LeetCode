#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0){
			return 0;
		}
		else{
			int curMax = 0;
			int *dp = new int[prices.size()];
			dp[0] = 0;
			for (int i = 1; i < prices.size(); ++i){
				dp[i] = max(0, dp[i - 1] + prices[i] - prices[i - 1]);
				if (dp[i]>curMax){
					curMax = dp[i];
				}
			}
			return curMax;
		}
	}
};

int main(){
	return 0;
}