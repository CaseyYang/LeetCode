#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		if (n == 0) return 0;
		vector<int> result = vector<int>();
		result.push_back(0);
		for (int i = 1; i <= n; ++i){
			result.push_back(i);
			for (int j = 1; j <= sqrt(i); ++j){
				result[i] = min(result[i], 1 + result[i - j*j]);
			}
		}
		return result[n];
	}
};