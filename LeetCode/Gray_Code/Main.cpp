#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		int size = 1 << n;
		vector<int> grayCodes;
		grayCodes.resize(size);
		for (int i = 0; i < size; i++){
			int gCode = i ^ i >> 1;
			grayCodes[i] = gCode;
		}
		return grayCodes;
	}
};

int main(){
	Solution s;
	s.grayCode(3);
	return 0;
}