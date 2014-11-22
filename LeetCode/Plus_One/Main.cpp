#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		vector<int> result = vector<int>();
		if (digits.size() == 0) return result;
		int sign = 1;
		for (int i = digits.size() - 1; i >= 0; --i){
			int tmp = digits[i] + sign;
			result.push_back(tmp % 10);
			sign = tmp / 10;
		}
		if (sign > 0) result.push_back(sign);
		reverse(result.begin(), result.end());
		return result;
	}
};
int main(){
	return 0;
}