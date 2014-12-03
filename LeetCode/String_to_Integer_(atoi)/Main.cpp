#include<iostream>
#include<string>
class Solution {
public:
	int atoi(const char *str) {
		if (str == NULL) return 0;
		int result = 0;
		bool isNegative = false;
		bool isInvalid = false;
		bool isChanged = false;
		int index = 0;
		while (str[index] != '\0'){
			if (str[index] != ' ') break;
			++index;
		}
		for (; str[index] != '\0'; ++index){
			if (str[index] == '-' || str[index] == '+'){
				if (!isChanged){
					isNegative = (str[index] == '-');
					isChanged = true;
					continue;
				}
				else{
					return 0;
				}
			}
			else{
				if (str[index]<'0' || str[index]>'9'){
					break;
				}
				else{
					int num = str[index] - '0';
					if (result > INT_MAX / 10 || (result == INT_MAX / 10 && num > INT_MAX % 10)){
						if (isNegative){
							return INT_MIN;
						}
						return INT_MAX;
					}
					result = result * 10 + num;
				}
			}
		}
		if (isNegative){
			return -result;
		}
		else{
			return result;
		}
	}
};