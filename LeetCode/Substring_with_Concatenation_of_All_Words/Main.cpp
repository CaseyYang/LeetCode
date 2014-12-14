#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		if (L.size() == 0) return result;
		map<string, int> ms;
		for (int i = 0; i < L.size(); ++i){
			++ms[L[i]];
		}
		int wordLength = L[0].size();
		for (int i = 0; i < S.size() - L.size()*wordLength + 1; ++i){
			map<string, int> ms2;
			bool valid = true;
			for (int j = 0; j < L.size(); ++j){
				string tmpStr = S.substr(i + j*wordLength, wordLength);
				++ms2[tmpStr];
				if (ms2[tmpStr] > ms[tmpStr]){
					valid = false;
					break;
				}
			}
			if (valid) result.push_back(i);
		}
		return result;
	}
};
int main(){
	vector<string> L;
	L.push_back("a");
	//L.push_back("a");
	string S = "a";
	Solution s;
	cout << s.findSubstring(S, L).size() << endl;
	return 0;
}