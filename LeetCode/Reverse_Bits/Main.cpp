#include<iostream>
using namespace std;

typedef unsigned int uint32_t;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		int count = 0;
		uint32_t result = 0;
		do{
			result = (result << 1) + (n & 1);
			n = n >> 1;
			count++;
		} while (count < 32);
		return result;
	}
};

int main(){
	Solution s;
	s.reverseBits(4);
	return 0;
}