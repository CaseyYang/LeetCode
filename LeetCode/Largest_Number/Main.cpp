#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool compare(string &s1, string &s2){
		for (int i = 0; i < s1.size() && i < s2.size(); ++i){
			if (s1[i] == s2[i]) continue;
			else return s1[i] > s2[i];
		}
		string sa = s1.size() < s2.size() ? s1 : s2;
		string sb = s1.size() > s2.size() ? s1 : s2;
		int start = sa.size() - 1;
		for (int i = start + 1; i < sb.size(); ++i){
			if (sa[start] == sb[i]) continue;
			else{
				return sa[start] > sb[i];
			}
		}
		return true;
	}
	void specialSort(int start, int end, vector<string> &nums){
		if (start < end){
			int j = start - 1;
			for (int i = start; i < end; ++i){
				if (!compare(nums[i], nums[end])){
					++j;
					swap(nums[i], nums[j]);
				}
			}
			++j;
			swap(nums[j], nums[end]);
			specialSort(start, j - 1, nums);
			specialSort(j + 1, end, nums);
		}
	}
	string largestNumber(vector<int> &num) {
		vector<string> numStrs;
		for (int i = 0; i < num.size(); ++i){
			stringstream ss;
			ss << num[i];
			string tmpStr;
			ss >> tmpStr;
			numStrs.push_back(tmpStr);
		}
		specialSort(0, num.size() - 1, numStrs);
		string result;
		for (int i = 0; i < numStrs.size(); ++i){
			string tmpStr = numStrs[i];
			result += tmpStr;
		}
		return result;
	}
};
int main(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	Solution s;
	s.largestNumber(nums);
	return 0;
}