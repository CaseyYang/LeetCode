#include<iostream>
using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		unsigned int mask = 1;
		mask = mask << 31;
		int i = 0;
		unsigned int result = 0;
		while (i < 32){
			if ((m&mask) == (n&mask)){
				result = result << 1;
				result += (!(m&mask) == 0);
				m = m << 1;
				n = n << 1;
				++i;
			}
			else{
				break;
			}
		}
		result = result << (31 - i + 1);
		return result;
	}

	//better solution from the web
	//int rangeBitwiseAnd(int m, int n) {
	//	int d = INT_MAX;
	//	while ((m & d) != (n & d)) {
	//		d <<= 1;
	//	}
	//	return m & d;
	//}

	//int rangeBitwiseAnd(int m, int n) {
	//	int i = 0;
	//	while (m != n) {
	//		m >>= 1;
	//		n >>= 1;
	//		++i;
	//	}
	//	return (m << i);
	//}
};

int main(){
	Solution s;
	cout << s.rangeBitwiseAnd(5, 5) << endl;
	return 0;
}