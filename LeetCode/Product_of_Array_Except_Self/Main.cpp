#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		if (nums.size() == 2 && nums[0] == nums[1] && nums[0] == 0){
			vector<int> result;
			result.push_back(0);
			result.push_back(0);
			return result;
		}
		int v1 = 1;
		int v2 = 1;
		for (int i = 1; i < nums.size(); ++i){
			v2 = v2*nums[i];
		}
		vector<int> result = vector<int>();
		for (int i = 0;i<nums.size(); ++i){
			if (i == 0) {
				result.push_back(v2);
				continue;
			}
			if (i == nums.size() - 1){
				v1 = v1*nums[i - 1];
				result.push_back(v1);
				continue;
			}
			v1 = v1*nums[i - 1];
			if (nums[i] == 0){
				v2 = 1;
				for (int j = i+1; j < nums.size(); ++j){
					v2 = v2*nums[j];
				}
			}
			else{
				v2 = v2 / nums[i];
			}			
			result.push_back(v1*v2);
		}
		return result;
	}
};