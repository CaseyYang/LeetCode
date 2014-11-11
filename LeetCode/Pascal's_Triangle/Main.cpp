#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int>> results = vector<vector<int>>();
		if (numRows >= 1){
			auto result = vector<int>();
			result.push_back(1);
			results.push_back(result);
		}
		if (numRows >= 2){
			auto result = vector<int>();
			result.push_back(1);
			result.push_back(1);
			results.push_back(result);
		}
		if (numRows >= 3){
			for (int i = 3; i <= numRows; ++i){
				auto result = vector<int>();
				result.push_back(1);
				for (int j = 0; j+1 < i-1; ++j){
					result.push_back(results.back()[j] + results.back()[j + 1]);
				}
				result.push_back(1);
				results.push_back(result);
			}
		}
		return results;
	}
};

int main(){
	return 0;
}