#include<iostream>
using namespace std;
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int start = 0, end = n - 1;
		while (start <= end){
			if (A[start] == elem){
				while (A[end] == elem&&end > start) --end;
				if (start == end) break;
				swap(A[start], A[end]);
				--end;
			}
			else{
				++start;
			}
		}
		return start;
	}
};
int main(){
	return 0;
}