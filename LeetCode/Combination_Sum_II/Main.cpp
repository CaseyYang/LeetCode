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
			if (start < nums.size()){
				if (nums[start] <= sum){
					tmpResult.push_back(nums[start]);
					DFS(nums, start + 1, sum - nums[start]);
					tmpResult.pop_back();
				}
				while (start + 1 < nums.size() && nums[start] == nums[start + 1]){
					++start;
				}
				if (start + 1 < nums.size()) {
					DFS(nums, start + 1, sum);
				}
			}
		}
	}
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
		if (candidates.size() == 0) return result;
		sort(candidates.rbegin(), candidates.rend());
		DFS(candidates, 0, target);
		return result;
	}
};
int main(){
	return 0;
}