#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		if (matrix.size() == 0) return;
		int height = matrix.size();
		for (int i = 0; i < (height + 1) / 2; ++i){
			for (int j = 0; j < (height + 1) / 2; ++j){
				int tmp = matrix[i][j];
				int sourceX = height - 1 - j, sourceY = i;
				int targetX = i, targetY = j;
				for (int k = 0; k < 3; ++k){
					matrix[targetX][targetY] = matrix[sourceX][sourceY];
					targetX = sourceX;
					targetY = sourceY;
					sourceX = height - 1 - targetY;
					sourceY = targetX;
				}
				matrix[targetX][targetY] = tmp;
			}
		}
		return;
	}
};
int main(){

}