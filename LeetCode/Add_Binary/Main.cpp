#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		vector<char> tmp = vector<char>();
		int aLength = a.size() - 1;
		int bLength = b.size() - 1;
		int sign = 0;
		for (; aLength >= 0 && bLength >= 0; --aLength, --bLength){
			if (a[aLength] == '1'&&b[bLength] == '1'){
				if (sign == 1){
					tmp.push_back(1);
				}
				else{
					tmp.push_back(0);
				}
				sign = 1;
				continue;
			}
			if (a[aLength] == b[bLength]){
				if (sign == 1){
					tmp.push_back(1);
					sign = 0;
				}
				else{
					tmp.push_back(0);
				}
				continue;
			}
			else{
				if (sign == 1){
					tmp.push_back(0);
				}
				else{
					tmp.push_back(1);
				}
				continue;
			}
		}
		if (aLength != -1){
			for (; aLength >= 0; --aLength){
				if (a[aLength] == '1'){
					if (sign == 1) tmp.push_back(0);
					else tmp.push_back(1);
				}
				else{
					if (sign == 1) {
						tmp.push_back(1);
						sign = 0;
					}
					else{
						tmp.push_back(0);
					}
				}
			}
		}
		if (bLength != -1){
			for (; bLength >= 0; --bLength){
				if (b[bLength] == '1'){
					if (sign == 1) tmp.push_back(0);
					else tmp.push_back(1);
				}
				else{
					if (sign == 1) {
						tmp.push_back(1);
						sign = 0;
					}
					else{
						tmp.push_back(0);
					}
				}
			}
		}
		if (sign == 1){
			tmp.push_back(1);
		}
		string result = "";
		for (int i = tmp.size() - 1; i >= 0; --i){
			result += ('0' + tmp[i]);
		}
		return result;
	}
};
int main(){
	return 0;
}