#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int total = (0 + nums.size())*(nums.size() + 1) / 2;
		int total2 = 0;
		for (int i = 0; i < nums.size(); ++i){
			total2 += nums[i];
		}
		return total - total2;
	}
};