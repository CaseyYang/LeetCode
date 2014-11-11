#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> tmpResults = vector<int>(rowIndex + 1);
		if (rowIndex == 0){
			tmpResults[0] = 1;
			return tmpResults;
		}
		else{
			long double tmp1 = 1;
			long double tmp2 = 1;
			for (int j = 0; j <= rowIndex / 2; ++j){
				if (j == 0 || j == rowIndex){
					tmpResults[0] = 1;
				}
				else{
					tmp1 *= (rowIndex - j + 1);
					tmp2 *= j;
					tmpResults[j] = tmp1 / tmp2;
				}
				tmpResults[rowIndex - j] = tmpResults[j];
			}
			return tmpResults;
		}
	}
};

int main(){
	Solution s;
	vector<int> results = s.getRow(18);
	for (int i = 0; i < results.size(); ++i){
		cout << results[i] << " ";
	}
	cout << endl;
	return 0;
}