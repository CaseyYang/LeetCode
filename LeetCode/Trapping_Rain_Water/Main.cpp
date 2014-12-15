#include<iostream>
using namespace std;
class Solution {
public:
	int trap(int A[], int n) {
		int bricks = 0;
		int count = 0;
		int last = 0;
		for (int i = 1; i < n; ++i){
			if (A[i] >= A[last]){
				if (i != last + 1){
					count += (i - last - 1)*A[last];
					count -= bricks;
				}
				bricks = 0;
				last = i;
			}
			else{
				bricks += A[i];
			}
		}
		last = n - 1;
		bricks = 0;
		for (int i = n - 2; i >= 0; --i){
			if (A[last] < A[i]){
				if (i != last - 1){
					count += (last - i - 1)*A[last];
					count -= bricks;
				}
				bricks = 0;
				last = i;
			}
			else{
				bricks += A[i];
			}
		}
		return count;
	}
};
int main(){
	return 0;
}