#include<iostream>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> result;
	void sort(vector<int> &num, int start, int end){
		if (start < end){
			int j = start - 1;
			for (int i = start; i < end; ++i){
				if (num[i] < num[end]){
					++j;
					swap(num[i], num[j]);
				}
			}
			++j;
			swap(num[j], num[end]);
			sort(num, start, j - 1);
			sort(num, j + 1, end);
		}
	}
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		if (num.size() == 0) return result;
		sort(num, 0, num.size() - 1);
		set <vector<int>> setResult;
		for (int i = 0; i < num.size(); ++i){
			if (num[i]>target) break;
			for (int j = i + 1; j < num.size(); ++j){
				if (num[i] + num[j] > target) break;
				for (int m = j + 1, n = num.size() - 1; m < n;){
					if (target - num[i] - num[j] == num[m] + num[n]){
						vector<int> tmpResult;
						tmpResult.push_back(num[i]);
						tmpResult.push_back(num[j]);
						tmpResult.push_back(num[m]);
						tmpResult.push_back(num[n]);
						setResult.insert(tmpResult);
						++m;
						--n;
					}
					else{
						if (target - num[i] - num[j] < num[m] + num[n]){
							--n;
						}
						else{
							++m;
						}
					}
				}
			}
		}
		result = vector<vector<int>>(setResult.begin(), setResult.end());
		return result;
	}
};
int main(){
	vector<int> input;
	//1 0 -1 0 -2 2
	input.push_back(1);
	input.push_back(0);
	input.push_back(-1);
	input.push_back(0);
	input.push_back(-2);
	input.push_back(2);
	Solution s;
	s.fourSum(input, 0);
	cout << s.result.size() << endl;
	return 0;
}