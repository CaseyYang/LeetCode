#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		set<int> s;
		for (int i = 0;i<nums.size();++i)
		{
			int var = nums[i];
			if (s.find(var) != s.end()) return true;
			else{
				s.insert(var);
			}
		}
		return false;
	}
};

int main(){
	return 0;
}