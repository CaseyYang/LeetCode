#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.size() == 0) return 0;
		int height = grid.size();
		int width = grid[0].size();
		for (int i = 0; i < grid.size(); ++i){
			for (int j = 0; j < grid[i].size(); ++j){
				if (i == 0){
					if (j != 0){
						grid[i][j] += grid[i][j - 1];
					}
				}
				else{
					grid[i][j] += min(min(grid[i][j - 1], grid[i - 1][j]), grid[i - 1][j - 1]);
				}
			}
		}
		return grid[height - 1][width - 1];
	}
};
int main(){
	return 0;
}