#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {

		if (nums.size() == 0) return 0;
		int i = 0;
		int j = 0;
		int cur = nums[0];
		int min = nums.size() + 1;
		while (true){
			cout << i << ' ' << j << ' ' << cur << " " << min << endl;
			if (cur >= s){
				min = j - i + 1 < min ? j - i + 1 : min;
				if (i < j){
					++i;
					cur = cur - nums[i - 1];
				}
				else{
					return min;
				}
			}
			else{
				if (j < nums.size() - 1){
					++j;
					cur += nums[j];
				}
				else{
					if (min == nums.size() + 1){
						min = 0;
					}
					return min;
				}
			}
		}
	}
};

int main(){
	//int a[10] = { 5, 1, 3, 5, 10, 7, 4, 9, 2, 8 };
	int a[6] = { 2, 3, 1, 2, 4, 3 };
	vector<int> s = vector<int>();
	for (int i = 0; i < 6; ++i){
		s.push_back(a[i]);
	}
	Solution ss;
	cout << ss.minSubArrayLen(7, s) << endl;
	return 0;
}