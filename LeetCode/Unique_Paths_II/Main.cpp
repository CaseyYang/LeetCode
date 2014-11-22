#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.size() == 0) return 0;
		vector<int> dp = vector<int>(obstacleGrid[0].size());
		int route = 1;
		for (int i = 0; i < obstacleGrid[0].size(); ++i){
			if (route == 1 && obstacleGrid[0][i] != 1){
				dp[i] = route;
			}
			else{
				route = 0;
				dp[i] = route;
			}
		}
		for (int i = 1; i < obstacleGrid.size(); ++i){
			for (int j = 0; j < obstacleGrid[i].size(); ++j){
				if (j == 0) {
					if (obstacleGrid[i][j] == 1){
						dp[j] = 0;
					}
				}
				else{
					if (obstacleGrid[i][j] != 1){
						dp[j] += dp[j - 1];
					}
					else{
						dp[j] = 0;
					}
				}
			}
		}
		return dp[obstacleGrid[0].size() - 1];
	}
};
int main(){
	return 0;
}