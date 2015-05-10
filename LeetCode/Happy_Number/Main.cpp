#include<iostream>
#include<set>
#include<sstream>
using namespace std;

class Solution {
public:
	set<int> nums;
	bool isHappy(int n) {
		cout << n << endl;
		int curResult = 0;
		stringstream ss;
		ss << n;
		string s;
		ss >> s;
		for (int i = 0; i < s.length(); ++i){
			curResult += (s[i] - '0')*(s[i] - '0');
		}
		if (curResult == 1){
			return true;
		}
		else{
			if (nums.find(curResult) != nums.end()){
				return false;
			}
			else{
				nums.insert(n);
				return isHappy(curResult);
			}
		}
	}
};

int main(){
	Solution s=Solution();
	cout << s.isHappy(7) << endl;
	return 0;
}