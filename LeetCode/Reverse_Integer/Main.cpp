#include<iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		bool isNegative = false;
		if (x < 0) {
			x = -x;
			isNegative = true;
		}
		if (x < 0) return 0;
		int result = 0;
		while (x > 0){
			int num = x % 10;
			x = x / 10;
			if (INT_MAX / 10 < result || INT_MAX / 10 == result&&num > INT_MAX % 10) return 0;
			result = result * 10 + num;
		}
		if (isNegative){
			return -result;
		}
		else{
			return result;
		}
	}
};
int main(){
	return 0;
}