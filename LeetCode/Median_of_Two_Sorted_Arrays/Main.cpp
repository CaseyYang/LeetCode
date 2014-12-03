#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	double DFS(int A[], int m, int B[], int n, int k){
		if (m > n) return DFS(B, n, A, m, k);//保证第一个参数的数组元素个数小于第二个参数的数组元素个数
		if (m == 0) return B[k - 1];//因为第一个参数的数组元素个数总小于第二个参数的数组元素个数，所以只可能第一个参数的数组元素个数为0；为0时，只考虑数组B
		if (k == 1) return min(A[0], B[0]);//当选第一个元素时，两个数组头比一比就行
		int pa = min(k / 2, m);//对数组A切割的位置，不能超过m，否则会越界
		int pb = k - pa;//确定数组A的切割位置后，B数组中切多少也就能确定了
		if (A[pa - 1] > B[pb - 1]){
			//说明第k个数不可能出现在B[0]~B[pb-1]中，等价于可能出现在B[pb]~B[n]中（因为B[pb]~B[n]中元素也可能比A[pa-1]小）
			int *newB = B + pb;//因为是切掉B[0]~B[pb-1]，所以都是减pb
			n = n - pb;
			k = k - pb;
			return DFS(A, m, newB, n, k);
		}
		if (A[pa - 1] < B[pb - 1]){
			//说明第k个数不可能出现在A[0]~A[pa-1]中，等价于可能出现在A[pa]~A[m]中（因为A[pa]~A[m]中元素也可能比B[pb-1]小）
			int *newA = A + pa;
			m = m - pa;
			k = k - pa;
			return DFS(newA, m, B, n, k);
		}
		if (A[pa - 1] == B[pb - 1]){
			//因为A[0]~A[pa-1]和B[0]~B[pb-1]合起来一共有k个元素，没有更多元素可能存在在A[pa]~A[m]或B[pb]~B[n]中
			return A[pa - 1];
		}
	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m + n;
		if(total == 0) return 0;
		if (total % 2 == 1){
			return DFS(A, m, B, n, total / 2 + 1);
		}
		else{
			return (DFS(A, m, B, n, total / 2) + DFS(A, m, B, n, total / 2 + 1)) / 2;
		}
	}
};
int main(){

	return 0;
}