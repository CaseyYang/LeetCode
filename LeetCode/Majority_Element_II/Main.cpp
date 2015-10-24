#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		if (nums.size() < 3) {
			set<int> s;
			for (int i = 0; i < nums.size(); ++i) {
				s.insert(nums[i]);
			}
			return vector<int>(s.begin(), s.end());
		}
		int can1 = nums[0];
		int can2 = nums[1];
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == can1&&count1 != 0) {
				++count1;
				continue;
			}
			if (nums[i] == can2&&count2 != 0) {
				++count2;
				continue;
			}
			if (count1 == 0) {
				can1 = nums[i];
				count1 = 1;
				continue;
			}
			if (count2 == 0) {
				can2 = nums[i];
				count2 = 1;
				continue;
			}
			--count1;
			--count2;
		}
		int count11 = 0;
		int count22 = 0;
		vector<int> result = vector<int>();
		bool pushed1 = false;
		bool pushed2 = false;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == can1&&count1>0) ++count11;
			if (nums[i] == can2&&count2 > 0) ++count22;
			if (count11 > nums.size() / 3 && !pushed1) {
				result.push_back(can1);
				pushed1 = true;
			}
			if (count22 > nums.size() / 3 && !pushed2) {
				result.push_back(can2);
				pushed2 = true;
			}
		}
		return result;
	}
};