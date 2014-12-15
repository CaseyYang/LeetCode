#include<iostream>
#include<set>
using namespace std;
class Solution {
public:
	//int firstMissingPositive(int A[], int n) {
	//	set<int> s;
	//	for (int i = 0; i < n; ++i){
	//		if (A[i] > 0)s.insert(A[i]);
	//	}
	//	for (int i = 1; i < n + 1; ++i){
	//		if (s.find(i) == s.end()) return i;
	//	}
	//}
	int firstMissingPositive(int A[], int n) {
		int index = 0;
		while (index < n){
			if (A[index] == index + 1 || A[index] <= 0 || A[index] > n || A[index] == A[A[index] - 1]){
				++index;
			}
			else{
				swap(A[index], A[A[index] - 1]);
			}
		}
		cout << n << endl;
		for (int i = 0; i < n; ++i){
			if (A[i] != i + 1) return i + 1;
		}
		return n + 1;
	}
};
int main(){
	int A[] = { 0, 1, 2 };
	Solution s;
	s.firstMissingPositive(A, 3);
	return 0;
}