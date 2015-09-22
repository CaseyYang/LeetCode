

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool binarySearch(vector<int> &v, int start, int end, int target){
		int middle = (start + end) / 2;
		if (middle == start || middle == end){
			return target == v[start] || target == v[end];
		}
		if (v[middle] == target) return true;
		else{
			if (v[middle] > target) return binarySearch(v, start, middle - 1, target);
			if (v[middle] < target) return binarySearch(v, middle + 1, end, target);
		}
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int xIndex1 = matrix.size();
		int xIndex2 = -1;
		for (int i = 0; i < matrix.size(); ++i){
			if (matrix[i][0] <= target&&matrix[i].back() >= target){
				xIndex1 = i;
				break;
			}
		}
		for (int j = matrix.size() - 1; j >= 0; --j){
			if (matrix[j][0] <= target&&matrix[j].back() >= target){
				xIndex2 = j;
				break;
			}
		}
		if (xIndex2 < xIndex1) return false;
		int yIndex1 = matrix[0].size();
		int yIndex2 = -1;
		for (int i = 0; i < matrix[0].size(); ++i){
			if (matrix[0][i] <= target&&matrix.back()[i] >= target){
				yIndex1 = i;
				break;
			}
		}
		for (int j = matrix[0].size() - 1; j >= 0; --j){
			if (matrix[0][j] <= target&&matrix.back()[j] >= target){
				yIndex2 = j;
				break;
			}
		}
		if (yIndex2 < yIndex1) return false;
		for (int i = xIndex1; i <= xIndex2; ++i){
			if (binarySearch(matrix[i], yIndex1, yIndex2, target)){
				return true;
			}
		}
		return false;
	}
};