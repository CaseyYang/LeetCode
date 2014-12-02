#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int jump(int A[], int n) {
		if (n == 0 || n == 1) return 0;
		int lastMax = 0;
		int curMax = 0;
		int step = 0;
		int i = 0;
		while (i < n){
			if (i > curMax) return -1;
			if (i > lastMax) {
				++step;
				lastMax = curMax;
			}
			if (i + A[i] > curMax){
				curMax = i + A[i];
				if (curMax >= n - 1) return step + 1;
			}
			++i;
		}
	}
};
int main(){
	return 0;
}