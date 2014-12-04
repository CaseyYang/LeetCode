#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
	//Mancher算法
	string longestPalindrome(string s) {
		string tmpS = "#";
		for (int i = 0; i < s.size(); ++i){
			tmpS += s[i];
			tmpS += '#';
		}
		int *p = new int[tmpS.size()];
		int center = 0;//当前已找到的右界最远的回文串中心位置
		int rightBorder = 0;//当前已找到的回文串的最远的右界位置
		int leftMirror = 0;//以cneter为中心，当前遍历位置的左侧对应索引
		for (int i = 0; i < tmpS.size(); ++i){
			leftMirror = 2 * center - i;
			p[i] = rightBorder>i ? min(rightBorder - i, p[leftMirror]) : 0;
			while (i + p[i] + 1 < tmpS.size() && i - p[i] - 1 >= 0 && tmpS[i + p[i] + 1] == tmpS[i - p[i] - 1]){
				++p[i];
			}
			if (i + p[i] > rightBorder){
				rightBorder = i + p[i];
				center = i;
			}
		}
		cout << "here1" << endl;
		int curMax = 0;
		for (int i = 0; i < tmpS.size(); ++i){
			if (p[i]>curMax) {
				curMax = p[i];
				center = i;
			}
		}
		cout << "here1" << endl;
		string result = tmpS.substr(center - p[center], 2 * p[center] + 1);
		string result2;
		for (int i = 0; i < result.size(); ++i){
			if (result[i] != '#') result2 += result[i];
		}
		return result2;
	}
};
int main(){
	string s = "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc";
	Solution ss;
	ss.longestPalindrome(s);
	return 0;
}