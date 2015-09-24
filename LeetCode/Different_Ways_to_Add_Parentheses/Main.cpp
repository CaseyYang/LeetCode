#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> result = vector<int>();
		for (int i = 0; i < input.size(); ++i){
			if ('0' <= input[i] && input[i] <= '9'){
				continue;
			}
			else{
				vector<int> tmpResult1 = diffWaysToCompute(input.substr(0, i));
				vector<int> tmpResult2 = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
				for (int j = 0; j < tmpResult1.size(); ++j){
					for (int k = 0; k < tmpResult2.size(); ++k){
						switch (input[i]){
						case '+':
							result.push_back(tmpResult1[j] + tmpResult2[k]);
							break;
						case '-':
							result.push_back(tmpResult1[j] - tmpResult2[k]);
							break;
						case '*':
							result.push_back(tmpResult1[j] * tmpResult2[k]);
							break;
						}
					}
				}
			}
		}
		if (result.size() == 0){
			result.push_back(atoi(input.c_str()));
		}
		return result;
	}
};