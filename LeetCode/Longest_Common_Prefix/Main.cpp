#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string result = "";
		if (strs.size() == 0) return result;
		result = strs[0];
		for (int i = 1; i < strs.size(); ++i){
			if (result.size() == 0) return result;
			if (result.size() > strs[i].size()){
				result = result.substr(0, strs[i].size());
			}
			for (int j = 0; j < min(strs[i].size(), result.size()); ++j){
				if (result[j] != strs[i][j]){
					result = result.substr(0, j);
					break;
				}
			}
		}
		return result;
	}
};
int main(){
	return 0;
}