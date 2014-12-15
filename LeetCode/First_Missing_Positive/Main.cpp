#include<iostream>
#include<set>
using namespace std;
class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		set<int> s;
		for (int i = 0; i < n; ++i){
			if (A[i] > 0)s.insert(A[i]);
		}
		for (int i = 1; i < n + 1; ++i){
			if (s.find(i) == s.end()) return i;
		}
	}
};
int main(){
	return 0;
}