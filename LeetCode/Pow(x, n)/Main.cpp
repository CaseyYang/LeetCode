#include<iostream>
using namespace std;
class Solution {
public:
	double pow(double x, int n) {
		bool negative = false;
		if (n == 0) return 1;
		if (n == 1) return x;
		if (n == -1) return 1 / x;
		if (n == 2) return x*x;
		if (n == -2) return 1 / (x*x);
		if (n < 0) {
			n = -n;
			negative = true;
		}		
		int middle = n / 2;
		double answer = pow(x, middle);
		if (middle * 2 == n) answer = answer*answer;
		else answer = answer*answer*x;
		if (negative) return 1 / answer;
		else return answer;
	}
};
int main(){
	Solution s;
	return 0;
}