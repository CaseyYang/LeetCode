#include<iostream>
#include<string>
#include<vector>
using namespace std;

//class Solution {
//	typedef long long int i64;
//
//	string myS;
//	const char* s;
//	i64 target;
//	int slen;
//
//public:
//	vector<string> addOperators(const string& num, int t) {
//		myS = num;
//		slen = myS.size();
//		s = myS.c_str();
//		target = t;
//
//		vector<string> res;
//		char buf[slen * 2 + 1];
//
//		int lmax = (s[0] == '0' ? 1 : slen);
//		i64 v = 0;
//		for (int l = 1; l <= lmax; ++l) {
//			int c = s[l - 1];
//			v = v * 10 + (c - '0');   // add next digit
//			buf[l - 1] = c;  // only need to append the last digit
//			processTail(0, v, l, buf, l, res);
//		}
//		return res;
//	}
//
//	void processTail(i64 prevsum, i64 last, int pos, char* buf, int bufpos, vector<string>& res) {
//		if (pos == slen) {
//			// end of string
//			// check the value and save
//			if (prevsum + last == target) {
//				buf[bufpos] = 0;
//				res.push_back(buf);
//			}
//			return;
//		}
//
//		int lmax = (s[pos] == '0' ? 1 : slen - pos); // don't allow multichar intergers starting from a '0'
//		i64 v = 0;
//		for (int l = 1; l <= lmax; ++l) {
//			int c = s[pos + l - 1];
//			v = v * 10 + (c - '0');     // add next digit to v
//
//			buf[bufpos] = '+';
//			buf[bufpos + l] = c;      // only need to append the last digit of v
//			processTail(prevsum + last, v, pos + l, buf, bufpos + l + 1, res);
//
//			buf[bufpos] = '-';
//			processTail(prevsum + last, -v, pos + l, buf, bufpos + l + 1, res);
//
//			buf[bufpos] = '*';
//			processTail(prevsum, last*v, pos + l, buf, bufpos + l + 1, res);
//		}
//	}
//};

class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> res;
		addOperatorsDFS(num, target, 0, 0, "", res);
		return res;
	}
	void addOperatorsDFS(string num, int target, long long diff, long long curNum, string out, vector<string> &res) {
		if (num.size() == 0 && curNum == target) {
			res.push_back(out);
		}
		for (int i = 1; i <= num.size(); ++i) {
			string cur = num.substr(0, i);
			if (cur.size() > 1 && cur[0] == '0') return;
			string next = num.substr(i);
			if (out.size() > 0) {
				addOperatorsDFS(next, target, stoll(cur), curNum + stoll(cur), out + "+" + cur, res);
				addOperatorsDFS(next, target, -stoll(cur), curNum - stoll(cur), out + "-" + cur, res);
				addOperatorsDFS(next, target, diff * stoll(cur), (curNum - diff) + diff * stoll(cur), out + "*" + cur, res);
			}
			else {
				addOperatorsDFS(next, target, stoll(cur), stoll(cur), cur, res);
			}
		}
	}
};