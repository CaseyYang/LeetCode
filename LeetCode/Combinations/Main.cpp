#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> results = vector<vector<int>>();
	void DFS(int m, int k, vector<int> &result, int n){
		if (result.size() == k){
			results.push_back(result);
			return;
		}
		else{
			for (int i = m; i <= n; ++i){
				result.push_back(i);
				DFS(i + 1, k, result, n);
				result.pop_back();
			}
			return;
		}
	}
	vector<vector<int> > combine(int n, int k) {
		vector<int> result;
		DFS(1, k, result, n);
		return results;
	}
};
int main(){
	Solution s;
	s.combine(4, 2);
	for (int i = 0; i < s.results.size(); ++i){
		for (int j = 0; j < s.results[i].size(); ++j){
			cout << s.results[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}