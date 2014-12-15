#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		vector<vector<int>> tmpRes;
		tmpRes.push_back(vector<int>());
		tmpRes.push_back(vector<int>());
		for (int i = num2.size() - 1; i >= 0; --i){
			tmpRes[0].clear();
			for (int j = num2.size() - 1 - i; j > 0; --j){
				tmpRes[0].push_back(0);
			}
			int multiplyShift = 0;
			int singleNum2 = num2[i] - '0';
			for (int k = num1.size() - 1; k >= 0; --k){
				int singleNum1 = num1[k] - '0';
				int singleResult = singleNum1*singleNum2 + multiplyShift;
				multiplyShift = singleResult / 10;
				tmpRes[0].push_back(singleResult % 10);
			}
			if (multiplyShift > 0) tmpRes[0].push_back(multiplyShift);
			if (tmpRes[1].size() == 0) tmpRes[1] = tmpRes[0];
			else{
				int addShift = 0;
				for (int m = 0; m < tmpRes[0].size() && m<tmpRes[1].size(); ++m){
					int singleResult = tmpRes[0][m] + tmpRes[1][m] + addShift;
					tmpRes[1][m] = singleResult % 10;
					addShift = singleResult / 10;
				}
				if (tmpRes[1].size() > tmpRes[0].size()){
					for (int n = tmpRes[0].size(); n < tmpRes[1].size(); -++n){
						int singleResult = tmpRes[1][n] + addShift;
						tmpRes[1][n] = singleResult % 10;
						addShift = singleResult / 10;
					}
				}
				else{
					for (int n = tmpRes[1].size(); n < tmpRes[0].size(); ++n){
						int singleResult = tmpRes[0][n] + addShift;
						tmpRes[1].push_back(singleResult % 10);
						addShift = singleResult / 10;
					}
				}
				if (addShift > 0) tmpRes[1].push_back(addShift);
			}
		}
		reverse(tmpRes[1].begin(), tmpRes[1].end());
		string result;
		bool flag = false;
		for (int p = 0; p < tmpRes[1].size(); ++p){
			if (tmpRes[1][p] != 0){
				flag = true;
				result += tmpRes[1][p] + '0';
			}
			else{
				if (flag) result += tmpRes[1][p] + '0';
			}
		}
		if (result == "") result += '0';
		return result;
	}
};
int main(){
	string a = "9369162965141127216164882458728854782080715827760307787224298083754";
	string b = "7204554941577564438";
	Solution s;
	cout << s.multiply(a, b) << endl;
	return 0;
}