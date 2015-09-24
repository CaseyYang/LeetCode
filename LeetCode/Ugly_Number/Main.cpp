#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		if (num == 0) return false;
		set<int> nums = set<int>();
		nums.insert(2);
		nums.insert(3);
		nums.insert(5);
		int now = num;
		while (now!=1){
			int yu = 1;
			for (auto iter = nums.begin(); iter != nums.end(); ++iter){
				yu = now%(*iter);
				if (yu == 0){
					now = now / (*iter);
					break;
				}
			}
			if (yu != 0) return false;
		}
		return true;
	}
};