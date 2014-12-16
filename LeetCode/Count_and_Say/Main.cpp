#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	string countAndSay(int n) {
		vector<int> result;
		string resultStr = "";
		if (n > 0){
			if (n == 1) result.push_back(1);
			else{
				vector<int> lastResult;
				lastResult.push_back(1);
				for (int i = 2; i <= n; ++i){
					vector<int> curResult;
					int lastElement = -1;
					int count = 0;
					for (int j = 0; j < lastResult.size(); ++j){
						if (lastElement == -1){
							lastElement = lastResult[j];
							++count;
						}
						else{
							if (lastElement != lastResult[j]){
								curResult.push_back(count);
								curResult.push_back(lastElement);
								lastElement = lastResult[j];
								count = 1;
							}
							else{
								++count;
							}
						}
					}
					curResult.push_back(count);
					curResult.push_back(lastElement);
					lastResult = curResult;
				}
				result = lastResult;
			}
		}
		for (int i = 0; i < result.size(); ++i){
			resultStr += '0' + result[i];
		}
		return resultStr;
	}
};
int main(){

	return 0;
}