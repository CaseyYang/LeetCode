#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		int start = -1, end = -1;
		for (int i = 0; i < n; ++i){
			if (A[i] == target){
				if (start == -1){
					end = start = i;
				}
				else{
					if (end == i - 1){
						end = i;
					}
				}
			}
		}
		vector<int> result;
		result.push_back(start);
		result.push_back(end);
		return result;
	}
};
int main(){
	return 0;
}