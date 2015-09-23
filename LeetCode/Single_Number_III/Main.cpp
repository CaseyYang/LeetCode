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
		int mask = aXorB&(~(aXorB - 1));//ȡ���һ��Ϊ1�Ķ�����λ
		int a = 0;
		int b = 0;
		for (int i = 0; i < nums.size(); ++i){
			if ((mask&nums[i]) == 0){//ע��==�����ȼ�����&��������Ҫ������
				a ^= nums[i];
			}
			else{
				b ^= nums[i];
			}
		}
		return vector<int>({ a, b });
	}
};