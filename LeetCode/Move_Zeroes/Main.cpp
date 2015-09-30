#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int indexZero = 0;
		int indexNum = 0;
		for (indexZero = 0; indexZero < nums.size(); ++indexZero){
			if (nums[indexZero] == 0) break;
		}
		if (indexZero == nums.size()) return;
		for (indexNum = 0; indexNum < nums.size(); ++indexNum){
			if (indexNum>indexZero&&nums[indexNum] != 0) break;
		}
		if (indexNum == nums.size()) return;
		while (indexNum > indexZero&&indexNum!=nums.size()){
			swap(nums[indexNum], nums[indexZero]);
			for (; indexZero < nums.size(); ++indexZero){
				if (nums[indexZero] == 0) break;
			}
			for (; indexNum < nums.size(); ++indexNum){
				if (nums[indexNum] != 0) break;
			}
		}
		return;
	}
};

int main(){
	Solution s;
	vector<int> v = vector<int>({0,1,0,3,2,0});
	s.moveZeroes(v);
	for (int i = 0; i < v.size(); ++i){
		cout << v[i] << endl;
	}
	return 0;
}