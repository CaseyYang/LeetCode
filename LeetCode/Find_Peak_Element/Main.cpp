#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int function(const vector<int> &num, int start, int end){
		if (start == end) return start;
		if (start < end){
			if (num[start] > num[start + 1]) return start;
			if (num[end] > num[end - 1]) return end;
			int middle = (start + end) / 2;
			if (num[middle] > num[middle - 1] && num[middle] > num[middle + 1]) return middle;
			else{
				if (num[middle] < num[middle - 1]){
					return function(num, start, middle - 1);
				}
				else{
					return function(num, middle + 1, end);
				}
			}
		}
	}
	int findPeakElement(const vector<int> &num) {
		return function(num, 0, num.size() - 1);
	}
};
int main(){
	return 0;
}