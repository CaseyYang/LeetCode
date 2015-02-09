#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string result;
		long longNumerator = numerator;
		long longDenominator = denominator;
		int answer = longNumerator / longDenominator;
		stringstream ss;
		ss << answer;
		ss >> result;
		int remainder = longNumerator / longDenominator;
		if (remainder != 0){
			result += ".";
			longNumerator = remainder;
		}
	}
};
int main(){
	return 0;
}