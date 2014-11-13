#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> results;
	void DFS(vector<int> &S, int index, vector<int> &result){
		results.push_back(result);
		for (int i = index; i < S.size(); ++i){
			result.push_back(S[i]);
			DFS(S, i+1, result);
			result.pop_back();
		}
	}
	vector<vector<int> > subsets(vector<int> &S) {
		if (S.size() != 0){
			sort(S.begin(), S.end());
			vector<int> result;
			DFS(S, 0, result);
		}
		return results;
	}
};

int main(){
	return 0;
}