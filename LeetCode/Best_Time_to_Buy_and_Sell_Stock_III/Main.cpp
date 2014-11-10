#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.size() == 0 || prices.size() == 1){
			return 0;
		}
		else{
			int *sellDays = new int[prices.size()];
			sellDays[0] = 0;
			int *buyDays = new int[prices.size()];
			buyDays[prices.size() - 1] = 0;
			int *dp = new int[prices.size()];
			dp[0] = 0;
			int totalMax = 0;
			for (int sellDay = 1; sellDay < prices.size(); ++sellDay){
				sellDays[sellDay] = 0;
				dp[sellDay] = max(dp[sellDay - 1] + prices[sellDay] - prices[sellDay - 1], 0);
				sellDays[sellDay] = dp[sellDay] > sellDays[sellDay - 1] ? dp[sellDay] : sellDays[sellDay - 1];
			}
			dp[prices.size() - 1] = 0;
			for (int buyDay = prices.size() - 2; buyDay >= 0; --buyDay){
				dp[buyDay] = max(dp[buyDay + 1] + (prices[buyDay + 1] - prices[buyDay]), 0);
				buyDays[buyDay] = dp[buyDay] > buyDays[buyDay + 1] ? dp[buyDay] : buyDays[buyDay + 1];
			}
			for (int i = 0; i < prices.size(); ++i){
				int cur = buyDays[i] + sellDays[i];
				totalMax = totalMax>cur ? totalMax : cur;
			}
			return totalMax;
		}
	}
};

int main(){
	return 0;
}