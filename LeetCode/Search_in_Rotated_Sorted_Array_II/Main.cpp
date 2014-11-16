#include<iostream>
using namespace std;
class Solution {
public:
	int resultIndex;
	bool recursion(int A[], int start, int end, int target){
		if (start <= end){
			int middleIndex = (start + end) / 2;
			if (target == A[middleIndex]) {
				resultIndex = middleIndex;
				return true;
			}
			if (target == A[start]) {
				resultIndex = start;
				return true;
			}
			if (target == A[end]) {
				resultIndex = end;
				return true;
			}
			else{
				if (A[start] < A[end]){
					if (target < A[middleIndex]) return recursion(A, start, middleIndex - 1, target);
					else return recursion(A, middleIndex + 1, end, target);
				}
				if (A[start] > A[end]){
					if (A[middleIndex] >= A[start]){
						if (target > A[middleIndex]) return recursion(A, middleIndex + 1, end, target);
						else{
							if (target > A[start]) return recursion(A, start, middleIndex - 1, target);
							else return recursion(A, middleIndex + 1, end, target);
						}
					}
					else{//A[middleIndex]<A[start]
						if (target < A[middleIndex]) return recursion(A, start, middleIndex - 1, target);
						else{//target>A[middleIndex]
							if (target > A[start]) return recursion(A, start, middleIndex - 1, target);
							else return recursion(A, middleIndex + 1, end, target);
						}
					}
				}
				if (A[start] == A[end]){
					return recursion(A, start, middleIndex - 1, target) || recursion(A, middleIndex + 1, end, target);
				}
			}
		}
		return false;
	}
	bool search(int A[], int n, int target) {
		if (n == 0) return -1;
		return recursion(A, 0, n - 1, target);
	}
};
int main(){
	return 0;
}