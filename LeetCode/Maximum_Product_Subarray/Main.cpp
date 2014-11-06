#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n) {
		if (n == 1) return A[0];
		int* maxs = new int[n];
		maxs[0] = A[0];
		int* mins = new int[n];
		mins[0] = A[0];
		for (int i = 1; i < n; ++i){
			maxs[i] = max(max(maxs[i - 1]*A[i], A[i]), mins[i - 1] * A[i]);
			mins[i] = min(min(mins[i - 1]*A[i], A[i]), maxs[i - 1] * A[i]);
		}
		int ans = A[0];
		for (int i = 0; i < n; ++i){
			if (maxs[i]>ans){
				ans = maxs[i];
			}
		}
		return ans;
	}
};

int main(){
	Solution s;
	int A[] = { -2, 0, -1};
	cout << s.maxProduct(A, 3) << endl;
	return 0;
}