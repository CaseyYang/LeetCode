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

//通解：解决数组中个数找出超过n/k的元素可以使用Boyer-Moore算法
vector<int> majorityElement(vector<int>& nums,int k) {
	vector<int> values(k);
	vector<int> counts(k, 0);
	for (const int num : nums) {
		int index = 0;
		// 1. locate equal number.
		for (index = 0; index < k; ++index) {
			if (values[index] == num) {
				++counts[index];
				break;
			}
		}
		if (index != k) {
			continue;
		}
		// 2. check empty space.
		for (index = 0; index < k; ++index) {
			if (counts[index] == 0) {
				values[index] = num;
				counts[index] = 1;
				break;
			}
		}
		if (index != k) {
			continue;
		}
		// 3. decrease all counters.
		for (index = 0; index < k; ++index) {
			// promise: values[i] is valid and counts[i] > 0.
			--counts[index];
		}
	}
	// verify candidates.
	vector<int> ret;
	for (int index = 0; index < k; ++index) {
		if (counts[index] == 0) {
			continue;
		}
		counts[index] = 0;
		for (const int num : nums) {
			if (values[index] == num) {
				++counts[index];
			}
		}
		if (counts[index] > nums.size() / (k + 1)) {
			ret.push_back(values[index]);
		}
	}
	return ret;
}
