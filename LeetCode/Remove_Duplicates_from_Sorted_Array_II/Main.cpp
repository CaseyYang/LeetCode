#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n < 3) return n;
		int index1 = 0;
		int pre = INT_MAX;
		int length = 0;
		int count = 0;
		for (int i = 0; i < n; ++i){
			if (pre != A[i]){
				A[length] = A[i];
				++length;
				count = 0;
			}
			else{
				if (count == 0){
					A[length] = A[i];
					++length;
					++count;
				}
			}
			pre = A[i];
		}
		return length;
	}
};
int main(){
	return 0;
}