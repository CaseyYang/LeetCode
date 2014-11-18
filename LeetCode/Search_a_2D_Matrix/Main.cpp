#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool binarySearch(vector<int> &v, int target, int start, int end){
		if (start > end) return false;
		if (start == end){
			if (v[start] == target) return true;
			return false;
		}
		if (v[start] == target || v[end] == target){
			return true;
		}
		int middle = (start + end) / 2;
		if (v[middle] == target) return true;
		if (v[middle] < target) return binarySearch(v, target, middle + 1, end);
		else{
			return binarySearch(v, target, start, middle - 1);
		}
		return false;
	}
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		if (matrix.size() == 0) return false;
		if (matrix.size() == 1) return binarySearch(matrix[0], target, 0, matrix[0].size() - 1);
		int height = matrix.size();
		int width = matrix[0].size();
		for (int i = 0; i < height; ++i){
			if (matrix[i][0] == target || matrix[i][width - 1] == target) return true;
			else{
				if (matrix[i][0] < target && matrix[i][width - 1] > target)
				{
					return binarySearch(matrix[i], target, 0, width - 1);
				}
			}
		}
		return false;
	}
};
int main(){
	return 0;
}