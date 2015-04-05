#include<iostream>
using namespace std;

class Solution {
public:
	void rotate(int nums[], int n, int k) {
		//基础方法,时间复杂度O(k*n)，空间复杂度O(1)
		for (int i = 0; i < k; ++i){
			int tmp = nums[n - 1];
			for (int j = n - 1; j >= 1; --j){
				nums[j] = nums[j - 1];
			}
			nums[0] = tmp;
		}

		//时间复杂度O(1)，空间复杂度O(n)
		k = k%n;
		int *tmps = new int[n];
		memcpy(tmps, nums + n - k, sizeof(int)*k);
		memcpy(tmps + k, nums, sizeof(int)*(n - k));
		memcpy(nums, tmps, sizeof(int)*n);
	}
};

int main(){
	return 0;
}