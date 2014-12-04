#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	vector <vector<int>> result;
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
	vector<vector<int> > threeSum(vector<int> &num) {
		if (num.size() == 0) result;
		set<vector<int>> setResult;
		sort(num, 0, num.size() - 1);
		for (int i = 0; i < num.size(); ++i){
			if (num[i]>0) continue;
			for (int j = i + 1, k = num.size() - 1; j < k;){
				if (num[j] + num[k] > 0 - num[i]){
					--k;
				}
				else{
					if (num[j] + num[k] < 0 - num[i]){
						++j;
					}
					else{
						vector<int> tmpResult;
						tmpResult.push_back(num[i]);
						tmpResult.push_back(num[j]);
						tmpResult.push_back(num[k]);
						setResult.insert(tmpResult);
						--k;
						++j;
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
	//{-1 0 1 2 - 1 - 4
	input.push_back(-1);
	input.push_back(0);
	input.push_back(1);
	input.push_back(2);
	input.push_back(-1);
	input.push_back(-4);
	Solution s;
	s.threeSum(input);
	cout << s.result.size() << endl;
	return 0;
}