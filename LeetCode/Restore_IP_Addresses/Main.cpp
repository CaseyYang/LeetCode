#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
	void DFS(string s, vector<int> result, vector<string> &results){
		if (result.size() == 3){
			if (s.size() > 3 || s == ""){
				return;
			}
			else{
				if (s[0] == '0'&&s.size() > 1) return;
				int num = atoi(s.c_str());
				if (num > 255){
					return;
				}
				else{
					result.push_back(num);
					results.push_back(string());
					for (int i = 0; i < result.size(); ++i){
						stringstream ss;
						ss << result[i];
						string tmpStr = ss.str();
						results.back().append(tmpStr);
						if (i < result.size() - 1){
							results.back().append(".");
						}
					}
					return;
				}
			}
		}
		else{
			for (int i = 1; i <= 3 && i <= s.size(); ++i){
				string rawStr = s.substr(0, i);
				if (s[0] == '0'&&rawStr.size() > 1) continue;
				int num = atoi(rawStr.c_str());
				if (num <= 255){
					result.push_back(num);
					DFS(s.substr(i), result, results);
					result.pop_back();
				}
				else{
					return;
				}
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> results;
		if (s.size() < 4){
			return results;
		}
		vector<int> result;
		DFS(s, result, results);
		return results;
	}
};

int main(){
	string ss = "010010";
	Solution s;
	vector<string> results = s.restoreIpAddresses(ss);
	for (int i = 0; i < results.size(); ++i){
		cout << results[i] << endl;
	}
	return 0;
}