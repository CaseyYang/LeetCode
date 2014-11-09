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
			int *dp = new int[prices.size()];
			dp[0] = 0;
			for (int i = 1; i < prices.size(); ++i){
				dp[i] = max(dp[i - 1], dp[i - 1] + prices[i] - prices[i - 1]);
			}
			return dp[prices.size() - 1];
		}
	}
};

int main(){
	return 0;
}