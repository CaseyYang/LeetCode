#include<iostream>
using namespace std;
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x < 10) return true;
		int base = 1;
		while (x / base >= 10){
			base *= 10;
		}
		while (x){
			int n1 = x / base;
			int n2 = x % 10;
			if (n1 != n2) return false;
			else{
				x = x - n1*base;
				x = x / 10;
				base = base / 100;
			}
		}
		return true;
	}
};
int main(){
	return 0;
}