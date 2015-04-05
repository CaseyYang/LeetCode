#include<iostream>
using namespace std;

class Solution {
public:
	void rotate(int nums[], int n, int k) {
		//��������,ʱ�临�Ӷ�O(k*n)���ռ临�Ӷ�O(1)
		for (int i = 0; i < k; ++i){
			int tmp = nums[n - 1];
			for (int j = n - 1; j >= 1; --j){
				nums[j] = nums[j - 1];
			}
			nums[0] = tmp;
		}

		//ʱ�临�Ӷ�O(1)���ռ临�Ӷ�O(n)
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