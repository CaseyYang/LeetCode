#include<iostream>
using namespace std;

class Solution {
public:
	int recursion(int start, int end){
		if (start == end || start > end){
			return 1;
		}
		else{
			int count = 0;
			for (int i = start; i <= end; ++i){
				count += recursion(start, i - 1)*recursion(i + 1, end);
			}
			return count;
		}
	}

	int numTrees(int n) {
		if (n == 0){
			return 1;
		}
		else{
			return recursion(1, n);
		}
	}
};

int main(){

}