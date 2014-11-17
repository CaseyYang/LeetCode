#include<iostream>
#include<list>
using namespace std;
void output(int A[], int n){
	for (int i = 0; i < n; ++i){
		cout << A[i] << " ";
	}
	cout << endl;
}
class Solution {
public:
	void sortColors(int A[], int n) {
		int i = 0; // 0 pointer
		int j = n - 1; // 1 pointer
		int k = n - 1; // 2 pointer
		while (i <= j)
		{
			cout << i << "," << j << "," << k << endl;
			if (A[i] == 2)
			{
				int t = A[k];
				A[k] = A[i];
				A[i] = t;
				k--;
				if (k < j){ j = k; }
				output(A, n);
			}
			else
			{
				if (A[i] == 1)
				{
					int t = A[j];
					A[j] = A[i];
					A[i] = t;
					j--;
					output(A, n);
				}
				else
					i++;
			}
		}
	}
};
int main(){
	int A[] = { 1, 2, 1, 1, 0, 2, 1 };
	//int A[] = { 1, 2, 0 };
	Solution s;
	s.sortColors(A, sizeof(A) / 4);
	output(A, sizeof(A) / 4);
	return 0;
}