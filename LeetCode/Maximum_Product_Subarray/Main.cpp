#include<iostream>
using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n) {
		bool init = true;
		int currentMax = 1;
		int max = INT_MIN;
		for (int i = 0; i < n; ++i){
			if (A[i] * currentMax > currentMax||init){
				init = false;
				currentMax = A[i] * currentMax;
				if (currentMax > max){
					max = currentMax;
				}
			}
			else{
				currentMax = A[i];
			}
		}
		return max;
	}
};

int main(){
	Solution s;
	int A[] = { -2};
	cout << s.maxProduct(A, 1) << endl;
	return 0;
}