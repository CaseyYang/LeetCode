#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> result;
	vector<int> tmpResult;
	void DFS(vector<int> &nums, int start, int sum){
		if (sum == 0){
			result.push_back(tmpResult);
			sort(result.back().begin(), result.back().end());
		}
		else{
			if (nums[start] <= sum){
				tmpResult.push_back(nums[start]);
				DFS(nums, start, sum - nums[start]);
				tmpResult.pop_back();
			}
			if (start + 1 < nums.size()) {
				DFS(nums, start + 1, sum);
			}
		}
	}
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		if (candidates.size() == 0) return result;
		sort(candidates.rbegin(), candidates.rend());
		//mySort(candidates, 0, candidates.size() - 1);
		DFS(candidates, 0, target);
		return result;
	}
};
int  main(){
	int n[] = { 48, 22, 49, 24, 26, 47, 33, 40, 37, 39, 31, 46, 36, 43, 45, 34, 28, 20, 29, 25, 41, 32, 23 };
	vector<int> nums;
	for (int i = 0; i < sizeof(n) / 4; ++i){
		nums.push_back(n[i]);
	}
	Solution s;
	vector<vector<int>> result = s.combinationSum(nums, 69);
	return 0;
}