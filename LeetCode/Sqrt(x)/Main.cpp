#include<iostream>
using namespace std;
class Solution {
public:
	int sqrt(int x) {
		if (x == 1) return 1;
		unsigned long long start = 0;
		unsigned long long end = x / 2;
		unsigned long long middle = (start + end) / 2;
		unsigned long long result = middle*middle;
		while (start < end){
			if (result == x) return middle;
			if (result < x){
				start = middle + 1;
			}
			else{
				end = middle - 1;
			}
			middle = (start + end) / 2;
			result = middle*middle;
		}
		if (result > x) return middle - 1;
		else return middle;
	}
	//int sqrt(int x) {
	//	// Start typing your C/C++ solution below
	//	// DO NOT write int main() function
	//	unsigned long long begin = 0;
	//	unsigned long long end = (x + 1) / 2;
	//	unsigned long long mid;
	//	unsigned long long tmp;
	//	while (begin < end)
	//	{
	//		mid = begin + (end - begin) / 2;
	//		tmp = mid*mid;
	//		if (tmp == x)return mid;
	//		else if (tmp<x) begin = mid + 1;
	//		else end = mid - 1;
	//	}
	//	tmp = end*end;
	//	if (tmp > x)
	//		return end - 1;
	//	else
	//		return end;
	//}
};
int main(){
	Solution s;
	cout << s.sqrt(2147395599) << endl;
}