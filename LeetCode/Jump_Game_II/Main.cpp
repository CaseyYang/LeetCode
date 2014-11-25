#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int jump(int A[], int n) {
		vector<int> v = vector<int>(n);
		for (int i = 0; i < n; ++i) v[i] = 0;
		if (n <= 1) return 1;
		int i = 0;
		int farest = 0;
		while (i <= farest){
			if (farest == n - 1) return v[farest];
			farest = i + A[i];
			v[farest] = v[i] + 1;
		}
	}
};
int main(){
	return 0;
}