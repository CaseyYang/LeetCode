#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> result;
	void DFS(vector<int> &num, int start){
		if (start == num.size()){
			result.push_back(num);
		}
		else{
			for (int i = start; i < num.size(); ++i){
				swap(num[start], num[i]);
				DFS(num, start + 1);
				swap(num[start], num[i]);
			}
		}
	}
	vector<vector<int>> permute(vector<int> &num) {
		if (num.size() == 0) return result;
		DFS(num, 0);
		return result;
	}
};
int main(){
	return 0;
}