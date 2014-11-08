#include<iostream>
using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		int result = A[0];
		for (int i = 1; i < n; ++i){
			result = result^A[i];
		}
		return result;
	}
};


int main(){
	return 0;
}