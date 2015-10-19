#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int titleToNumber(string s) {
		int result = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			char a = s[i];
			result += (s[i] - 'A' + 1)*pow(26, s.size() - i-1);
		}
		return result;
	}
};
int main() {
	Solution s;
	cout << s.titleToNumber("AZ") << endl;
	return 0;
}