#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canJump(int A[], int n) {
		if (n == 0) return true;
		int maxIndex = 0;
		int index = 0;
		while (index <= maxIndex){
			maxIndex = max(maxIndex, A[index] + index);
			if (maxIndex >= n - 1){
				return true;
			}
			++index;
		}
		return false;
	}
};
int main(){
	return 0;
}