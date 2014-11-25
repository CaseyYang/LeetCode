#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//class Solution {
//public:
//	void internalpermuteUnique(vector<int> &num, int index, vector<int> &perm, vector<vector<int> > &result) {
//		int size = num.size();
//		if (size == index) {
//			result.push_back(perm);
//		}
//		else {
//			for (int i = index; i < size; ++i) {
//				if ((i > index) && (num[i] == num[index])) {
//					continue;
//				}
//				else {
//					swap(num[index], num[i]);
//					perm.push_back(num[index]);
//					internalpermuteUnique(num, index + 1, perm, result);
//					perm.pop_back();
//				}				
//			}
//			sort(num.begin() + index, num.end());
//		}
//	}
//	vector<vector<int> > permuteUnique(vector<int> &num) {
//		vector<vector<int> > result;
//		vector<int> perm;
//		sort(num.begin(), num.end());
//		internalpermuteUnique(num, 0, perm, result);
//		return result;
//	}
//};
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
	void DFS(vector<int> &num, int start){
		if (start == num.size()) {
			result.push_back(num);
			return;
		}
		for (int i = start; i < num.size(); ++i){
			if (i == start || i > start&& num[i] != num[i - 1]){
				swap(num[i], num[start]);
				DFS(num, start + 1);
				swap(num[i], num[start]);
			}
		}
	}
	vector<vector<int>> permuteUnique(vector<int> &num) {
		if (num.size() == 0) return result;
		sort(num, 0, num.size() - 1);
		DFS(num, 0);
		return result;
	}
};
int main(){
	return 0;
}