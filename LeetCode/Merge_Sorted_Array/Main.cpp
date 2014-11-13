#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		vector<int> tmp = vector<int>();
		
		for (int i = 0, j = 0; i < m || j < n;){
			if (i == m){
				while (j < n){
					tmp.push_back(B[j]);
					++j;
				}
				break;
			}
			if (j == n){
				while (i < m){
					tmp.push_back(A[i]);
					++i;
				}
				break;
			}
			if (A[i] < B[j]){
				tmp.push_back(A[i]);
				++i;
			}
			else{
				tmp.push_back(B[j]);
				++j;
			}
		}
		for (int i = 0; i < tmp.size(); ++i){
			A[i] = tmp[i];
		}
	}
};

int main(){
	return 0;
}