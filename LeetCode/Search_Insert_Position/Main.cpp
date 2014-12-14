#include<iostream>
using namespace std;
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int position = 0;
		for (int i = 0; i < n; ++i){
			if (A[i]>=target) return position;
			else{
				++position;
			}
		}
		return position;
	}
};
int main(){

	return 0;
}