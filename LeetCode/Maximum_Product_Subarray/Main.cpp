#include<iostream>
using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n) {
		int** matrix = new int*[n];
		int maxProduct = INT_MIN;
		for (int i = 0; i < n; ++i){
			matrix[i] = new int[n];
			for (int j = i; j < n; ++j){
				if (j == i){
					matrix[i][j] = A[i];
				}
				else{
					if (i > 0){
						if (matrix[i][j - 1] * A[j] > matrix[i - 1][j]){
							matrix[i][j] = matrix[i][j - 1] * A[j];
						}
						else{
							matrix[i][j] = matrix[i - 1][j];
						}
					}
					else{
						if (matrix[i][j - 1] * A[j] > A[j]){
							matrix[i][j] = matrix[i][j - 1] * A[j];
						}
						else{
							matrix[i][j] = A[j];
						}
					}
				}
				if (matrix[i][j] > maxProduct){
					maxProduct = matrix[i][j];
				}
			}
		}
		return maxProduct;
	}
};

int main(){
	Solution s;
	int A[4] = { 2, 3, -2, 4 };
	cout << s.maxProduct(A, 4) << endl;
	return 0;
}