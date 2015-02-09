#include<iostream>
#include<sstream>
#include<map>
using namespace std;
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0) return "0";
		if (denominator == 0) return "";
		string result, tmpStr;
		if (numerator > 0 && denominator < 0 || numerator < 0 && denominator>0) result = "-";
		long long longNumerator = numerator;//一定要long long。用long在遇到-2147483648还是会出错
		long long longDenominator = denominator;
		longNumerator = abs(longNumerator);
		longDenominator = abs(longDenominator);
		long long answer = longNumerator / longDenominator;
		stringstream ss;
		ss << answer;
		ss >> tmpStr;
		ss.clear();
		result += tmpStr;
		long long remainder = longNumerator % longDenominator;
		if (remainder != 0){
			cout << remainder << endl;
			map<long long, int> remainders;
			result += ".";
			remainder = remainder * 10;
			while (remainder != 0){
				if (remainders.find(remainder) != remainders.end()){
					string p1 = result.substr(0, remainders[remainder]);
					string p2 = result.substr(remainders[remainder]);
					result = p1 + "(" + p2 + ")";
					break;
				}
				remainders[remainder] = result.size();
				answer = remainder / longDenominator;
				ss << answer;
				ss >> tmpStr;
				ss.clear();
				result += tmpStr;
				remainder = (remainder % longDenominator) * 10;
			}
		}
		return result;
	}
};
int main(){
	Solution s;
	cout << s.fractionToDecimal(-1, -2147483648) << endl;
	return 0;
}