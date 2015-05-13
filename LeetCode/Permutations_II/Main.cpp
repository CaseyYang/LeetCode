#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void internalpermuteUnique(vector<int> &num, int index, vector<vector<int> > &result) {
		int size = num.size();
		if (size == index) {
			result.push_back(num);
		}
		else {
			for (int i = index; i < size; ++i) {
				if ((i > index) && (num[i] == num[index])) {
					continue;
				}
				else {
					swap(num[index], num[i]);
					internalpermuteUnique(num, index + 1, result);
				}				
			}
			sort(num.begin() + index, num.end());
		}
	}
	vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > result;
		sort(num.begin(), num.end());
		internalpermuteUnique(num, 0, result);
		return result;
	}
};
int main(){
	return 0;
}