#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool compare(string &s1, string &s2){
		string r1 = s1 + s2;
		string r2 = s2 + s1;
		stringstream ss;
		ss << r1;
		int r1Int,r2Int;
		ss >> r1Int;
		ss.clear();
		ss << r2;
		ss >> r2Int;
		return r1Int > r2Int;
	}
	void specialSort(int start, int end, vector<string> &nums){
		if (start < end){
			int j = start - 1;
			for (int i = start; i < end; ++i){
				cout << compare(nums[i], nums[end]) << endl;
				if (compare(nums[i], nums[end])){
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
		bool flag = false;
		for (int i = 0; i < num.size(); ++i){
			if (num[i] == 0) continue;
			else{
				flag = true;
				break;
			}
		}
		if (!flag){
			return "0";
		}
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
	nums.push_back(128);
	nums.push_back(12);
	Solution s;
	cout<<s.largestNumber(nums)<<endl;
	return 0;
}