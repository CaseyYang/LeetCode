#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string convertToTitle(int n) {
		string result = "";
		while (n != 0) {
			result = (char)('A' + (n - 1) % 26) + result;
			n = (n-1) / 26;
			cout << n << endl;
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.convertToTitle(52) << endl;
	return 0;
}