#include<iostream>
using namespace std;
class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;
		while (n)
		{
			res += n / 5;
			n /= 5;
		}
		return res;
	}
};
int main(){
	Solution s;
	cout<<s.trailingZeroes(32)<<endl;

	return 0;
}