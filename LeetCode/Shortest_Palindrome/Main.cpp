#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string shortestPalindrome(string s) {
		if (s.size() == 0 || s.size() == 1) return s;
		int lastLeftChr = s.size() / 2 - 1;
		string totalLeftStr = s.substr(0,lastLeftChr + 1);
		reverse(totalLeftStr.begin(), totalLeftStr.end());
		for (int i = 0; i <totalLeftStr.size(); ++i){
			string leftStr = totalLeftStr.substr(i);
			//cout <<"left: "<< leftStr << endl;
			int rightStrStart = lastLeftChr + 2 - i;
			//cout << "rightStrStart: " << rightStrStart << endl;
			if (leftStr.size() <= s.size() - rightStrStart){
				string rightStr = s.substr(rightStrStart, leftStr.size());
				//cout << "left: " << rightStr << endl;
				if (leftStr == rightStr){
					if (lastLeftChr + 2 - i + leftStr.size() == s.size()) return s;
					string bu = s.substr(rightStrStart + leftStr.size());
					reverse(bu.begin(), bu.end());
					bu += s;
					return bu;
				}
			}
			rightStrStart = lastLeftChr + 1 - i;
			//cout << "rightStrStart: " << rightStrStart << endl;
			if (leftStr.size() <= s.size() - rightStrStart){
				string rightStr = s.substr(rightStrStart, leftStr.size());
				//cout << "right: " << rightStr << endl;
				if (leftStr == rightStr){
					if (lastLeftChr + 1 - i + leftStr.size() == s.size()) return s;
					string bu = s.substr(rightStrStart + leftStr.size());
					reverse(bu.begin(), bu.end());
					bu += s;
					return bu;
				}
			}
		}
		string bu = s.substr(1);
		reverse(bu.begin(), bu.end());
		return bu + s;
	}
};
int main(){
	string s = "abbacd";
	Solution r;
	cout << r.shortestPalindrome(s) << endl;
}