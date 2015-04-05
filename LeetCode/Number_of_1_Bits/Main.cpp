#include<iostream>
using namespace std;

typedef unsigned int uint32_t;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int m = n;
		int count = 0;
		int result = 0;
		do{
			if (m & 1 == 1) ++result;
			m = m >> 1;
			count++;
		} while (count<32);
		return result;
	}
};

int main(){
	return 0;
}