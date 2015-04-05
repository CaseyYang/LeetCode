#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int> &num) {
		if (num.size() == 0) return 0;
		if (num.size() == 1) return num[0];
		else{
			vector<int> dp = vector<int>(num.size());
			dp[0] = num[0];
			dp[1] = max(dp[0], num[1]);
			for (int i = 2; i < num.size(); ++i){
				dp[i] = max(dp[i - 1], dp[i - 2] + num[i]);
			}
			return dp[num.size()-1];
		}
	}
};

int main(){
	return 0;
}