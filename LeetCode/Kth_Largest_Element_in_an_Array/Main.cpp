#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int j = -1;
		int middle = nums[nums.size() - 1];
		for (int i = 0; i < nums.size() - 1; ++i){
			if (nums[i] > middle){
				++j;
				swap(nums[i], nums[j]);
			}
		}
		++j;
		swap(nums[j], nums[nums.size() - 1]);
		if (j + 1 == k){
			return nums[j];
		}
		else{			
			if (j + 1>k){
				vector<int> next = vector<int>(nums.begin(), nums.begin() + j);
				return findKthLargest(next,k);
			}
			else{
				vector<int> next = vector<int>(nums.begin() + j + 1, nums.end());
				return findKthLargest(next, k-j-1);
			}
		}
	}
};
int main(){

}