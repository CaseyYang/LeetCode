#include<iostream>
using namespace std;
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int start = 0, loc = 0;
		int last = INT_MIN;
		for (int i = 0; i < n; ++i){
			if (A[i]>last){
				A[loc] = A[i];
				++loc;
				last = A[i];
			}
		}
		return loc;
	}
};
int main(){
	return 0;
}