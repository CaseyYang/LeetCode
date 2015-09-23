#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int aXorB = 0;
		for (int i = 0; i < nums.size(); ++i){
			aXorB ^= nums[i];
		}
		int mask = aXorB&(~(aXorB - 1));//取最后一个为1的二进制位
		int a = 0;
		int b = 0;
		for (int i = 0; i < nums.size(); ++i){
			if ((mask&nums[i]) == 0){//注意==的优先级高于&，所以需要加括号
				a ^= nums[i];
			}
			else{
				b ^= nums[i];
			}
		}
		return vector<int>({ a, b });
	}
};