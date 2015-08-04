#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1){
			return nums[0];
		}
		if (nums.size() == 2){
			return max(nums[0], nums[1]);
		}
		int last2 = nums[0];
		int last1 = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size() - 1; ++i){
			int tmp = last1;
			last1 = (last2 + nums[i])>last1 ? (last2 + nums[i]) : last1;
			last2 = tmp;
		}
		int ans1 = last1;
		int last2 = nums[1];
		int last1 = max(nums[1], nums[2]);
		for (int i = 3; i < nums.size(); ++i){
			int tmp = last1;
			last1 = (last2 + nums[i])>last1 ? (last2 + nums[i]) : last1;
			last2 = tmp;
		}
		return max(ans1, last1);
	}
};