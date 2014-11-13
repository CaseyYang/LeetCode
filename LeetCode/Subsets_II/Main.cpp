#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	//void dfs(vector<vector<int> >& ans, vector<int>&s, vector<int>&tmp, int start) {
	//	ans.push_back(tmp);

	//	for (int i = start; i < s.size(); ++i) {
	//		if (i != start && s[i] == s[i - 1]) continue; //select only once in every layer
	//		tmp.push_back(s[i]); //select
	//		dfs(ans, s, tmp, i + 1); //do recusive
	//		tmp.pop_back(); //delete
	//	}
	//}
	//vector<vector<int> > subsetsWithDup(vector<int> &S) {
	//	vector<vector<int> > ans;
	//	if (S.size() <= 0) return ans;
	//	vector<int> tmp;
	//	sort(S.begin(), S.end()); // sort
	//	dfs(ans, S, tmp, 0);
	//	return ans;
	//}

	vector<vector<int>> uniqueResults;

	void DFS(vector<int> &S, int start, vector<int> &result){
		uniqueResults.push_back(result);
		for (int i = start; i < S.size(); ++i){
			if (i != start&&S[i - 1] == S[i]) continue;
			result.push_back(S[i]);
			DFS(S, i + 1, result);
			result.pop_back();
		}
		return;
	}
	vector<vector<int>> subsetsWithDup(vector<int> &S) {
		if (S.size() == 0){
			return uniqueResults;
		}
		else{
			vector<int> result;
			sort(S.begin(), S.end());
			DFS(S, 0, result);
			return uniqueResults;
		}
	}
};

int main(){
	vector<int> v = vector<int>();
	for (int i = 0; i <= 10; ++i){
		v.push_back(i);
	}
	Solution s;
	cout << s.subsetsWithDup(v).size() << endl;
	return 0;
}