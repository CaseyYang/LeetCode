#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int result = 0;
		if (matrix.size() == 0) return result;
		vector<vector<int>> dp = vector<vector<int>>();
		for (int i = 0; i < matrix.size(); ++i){
			dp.push_back(vector<int>(matrix[0].size()));
			dp[i][0] = matrix[i][0] - '0';
		}
		for (int i = 0; i < matrix[0].size(); ++i){
			dp[0][i] = matrix[0][i] - '0';
			result = dp[0][i] > result ? dp[0][i] : result;
		}
		for (int i = 1; i < matrix.size(); ++i){
			for (int j = 1; j < matrix[i].size(); ++j){
				if (matrix[i][j] - '0'){
					int tmpMin = min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(dp[i - 1][j - 1], tmpMin) + 1;
				}
				else{
					dp[i][j] = matrix[i][j] - '0';
				}
				result = dp[i][j] > result ? dp[i][j] : result;
			}
		}
		return result*result;
	}
};
int main(){

	return 0;
}