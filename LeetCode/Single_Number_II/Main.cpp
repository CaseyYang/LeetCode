#include<iostream>
using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n){
		int results[32] = {0};
		for (int i = 0; i < 32; ++i){
			unsigned mask = 1 << i;
			unsigned val = 0;
			int count = 0;
			for (int j = 0; j < n; ++j){
				val = mask&A[j];
				if (val > 0){
					++count;
				}
			}
			results[31 - i] = count % 3;
		}
		if (results[0] == 0){
			int multi = 1;
			int result = 0;
			for (int i = 31; i >= 1; --i){
				result += results[i] * multi;
				multi = multi * 2;
			}
			return result;
		}
		else{
			int multi = 1;
			int result = 0;
			for (int i = 31; i >= 1; --i){
				result += (1 - results[i]) * multi;
				multi = multi * 2;
			}
			return -(result+1);
		}
	}
};

int main(){
	int A[10] = { -2, -2, 1, 1, -3, 1, -3, -3, -4, -2 };
	Solution s;
	s.singleNumber(A, 10);
	return 0;
}