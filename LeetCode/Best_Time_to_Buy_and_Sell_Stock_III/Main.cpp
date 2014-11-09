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
			int **dp = new int*[prices.size()];
			for (int i = 0; i < prices.size(); ++i){
				dp[i] = new int[prices.size()];
				for (int j = 0; j < prices.size(); ++j){
					dp[i][j] = prices[j] - prices[i];
				}
			}			
		}
	}
};

int main(){
	return 0;
}