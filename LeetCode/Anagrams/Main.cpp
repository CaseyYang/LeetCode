#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> result = vector<string>();
		if (strs.size() == 0) return result;
		map<string, int> mc = map<string, int>();
		for (int i = 0; i < strs.size(); ++i){
			string s = strs[i];
			sort(s.begin(), s.end());
			if (mc.find(s) == mc.end()){
				mc[s] = i;
			}
			else{
				if (mc[s] != -1){
					result.push_back(strs[mc[s]]);
					mc[s] = -1;
				}
				result.push_back(strs[i]);
			}
		}
		return result;
	}
};
int main(){
	return 0;
}