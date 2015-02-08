#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
class Solution {
public:
	long hash(string &s){
		long hashValue = 0;
		for (int i = 0; i < s.size(); ++i){
			hashValue += s[i];
			hashValue *= 10;
		}
		return hashValue;
	}
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		if (s.size() <= 10){
			return result;
		}
		else{
			set<long> subStrs;
			set<string> resultSet;
			int start = 0;
			for (int i = 9; i < s.size(); ++i,++start){
				string tmpStr = s.substr(start, 10);
				cout << tmpStr << endl;
				long tmpHashValue = hash(tmpStr);
				cout << tmpHashValue << endl;
				if (subStrs.find(tmpHashValue) == subStrs.end()){
					subStrs.insert(tmpHashValue);
				}
				else{
					resultSet.insert(tmpStr);
				}
			}
			result = vector<string>(resultSet.begin(), resultSet.end());
			return result;
		}
	}
};
int main(){
	Solution s;
	s.findRepeatedDnaSequences("AAAAAAAAAAA");
	return 0;
}