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
			for (int sellDay = 1; sellDay < prices.size(); ++sellDay){
				sellDays[sellDay] = 0;
				for (int i = 1; i <= sellDay; i++){
					dp[i] = max(dp[i - 1] + prices[i] - prices[i - 1], 0);
					sellDays[sellDay] = dp[i] > sellDays[sellDay] ? dp[i] : sellDays[sellDay];
				}
			}
			for (int buyDay = prices.size() - 1; buyDay >= 0; --buyDay){
				for (int i = prices.size() - 1; i >= buyDay; --i){
					dp[i] = max(dp[i + 1] + (prices[i + 1] - prices[i]), 0);
					buyDays[buyDay] = dp[i] > buyDays[buyDay] ? dp[i] : buyDays[buyDay];
				}
			}
			int totalMax = 0;
			for (int i = 0; i < prices.size(); ++i){
				int cur = buyDays[i] + sellDays[i];
				totalMax = totalMax>cur ? totalMax : cur;
			}
			return;
		}
	}
};

int main(){
	return 0;
}