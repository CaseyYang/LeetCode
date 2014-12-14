#include<iostream>
using namespace std;
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) return INT_MAX;
		if (dividend == INT_MIN){
			if (divisor == 1) return INT_MIN;
			if (divisor == -1) return INT_MAX;
			if (divisor == INT_MIN) return 1;
			if (divisor == INT_MAX) return -1;
		}
		if (dividend == INT_MAX){
			if (divisor == 1) return INT_MAX;
			if (divisor == -1) return -INT_MAX;
			if (divisor == INT_MIN) return 0;
			if (divisor == INT_MAX) return 1;
		}
		if (divisor == INT_MIN){
			if (dividend == INT_MIN) return 1;
			else return 0;
		}
		if (divisor == INT_MAX){
			if (dividend == INT_MIN || dividend == INT_MIN + 1) return -1;
			if (dividend == INT_MAX) return 1;
			else return 0;
		}
		long long a = abs((double)dividend);
		long long b = abs((double)divisor);
		long long res = 0;
		while (a >= b)
		{
			long long c = b;
			cout << "被除数：" << a << endl;
			cout << "除数：" << c << endl;
			for (int i = 0; a >= c; i++, c <<= 1)
			{
				cout << "c:" << c << endl;
				a -= c;
				res += 1 << i;
			}
			cout << "当前结果：" << res << endl;
		}
		return ((dividend ^ divisor) >> 31) ? (-res) : (res);
	}
};
int main(){
	Solution s;
	cout << s.divide(101, 20) << endl;
	return 0;
}