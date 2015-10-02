#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0;
		int fast = 0;
		for (slow = nums.back(), fast = nums[slow - 1]; slow != fast; slow = nums[slow - 1], fast = nums[nums[fast - 1] - 1]){
			cout << slow << ":" << nums[slow] << endl;
			cout << fast << ":" << nums[fast] << endl;
			cout << endl;
		}
		for (slow = nums.size(); slow != fast; slow = nums[slow - 1], fast = nums[fast - 1]){
			cout << slow << ":" << nums[slow] << endl;
			cout << fast << ":" << nums[fast] << endl;
			cout << endl;
		}
		return slow;
	}
};

int main(){
	vector<int> nums = vector<int>({ 2, 1, 1 });
	Solution  s;
	s.findDuplicate(nums);
}

