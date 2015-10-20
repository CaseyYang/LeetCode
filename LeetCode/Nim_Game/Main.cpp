#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//bool canWinNim(int n) {
	//	bool v[4];
	//	v[0] = true;
	//	v[1] = true;
	//	v[2] = true;
	//	for (int i = 3; i < n; ++i) {
	//		v[3] = !(v[2]&&v[1]&&v[0]);
	//		v[0] = v[1];
	//		v[1] = v[2];
	//		v[2] = v[3];
	//	}
	//	return v[3];
	//}
	bool canWinNim(int n) {
		return (n % 4) != 0;
	}
};