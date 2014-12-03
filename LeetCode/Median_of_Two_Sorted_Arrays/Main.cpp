#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	double DFS(int A[], int m, int B[], int n, int k){
		if (m > n) return DFS(B, n, A, m, k);//��֤��һ������������Ԫ�ظ���С�ڵڶ�������������Ԫ�ظ���
		if (m == 0) return B[k - 1];//��Ϊ��һ������������Ԫ�ظ�����С�ڵڶ�������������Ԫ�ظ���������ֻ���ܵ�һ������������Ԫ�ظ���Ϊ0��Ϊ0ʱ��ֻ��������B
		if (k == 1) return min(A[0], B[0]);//��ѡ��һ��Ԫ��ʱ����������ͷ��һ�Ⱦ���
		int pa = min(k / 2, m);//������A�и��λ�ã����ܳ���m�������Խ��
		int pb = k - pa;//ȷ������A���и�λ�ú�B�������ж���Ҳ����ȷ����
		if (A[pa - 1] > B[pb - 1]){
			//˵����k���������ܳ�����B[0]~B[pb-1]�У��ȼ��ڿ��ܳ�����B[pb]~B[n]�У���ΪB[pb]~B[n]��Ԫ��Ҳ���ܱ�A[pa-1]С��
			int *newB = B + pb;//��Ϊ���е�B[0]~B[pb-1]�����Զ��Ǽ�pb
			n = n - pb;
			k = k - pb;
			return DFS(A, m, newB, n, k);
		}
		if (A[pa - 1] < B[pb - 1]){
			//˵����k���������ܳ�����A[0]~A[pa-1]�У��ȼ��ڿ��ܳ�����A[pa]~A[m]�У���ΪA[pa]~A[m]��Ԫ��Ҳ���ܱ�B[pb-1]С��
			int *newA = A + pa;
			m = m - pa;
			k = k - pa;
			return DFS(newA, m, B, n, k);
		}
		if (A[pa - 1] == B[pb - 1]){
			//��ΪA[0]~A[pa-1]��B[0]~B[pb-1]������һ����k��Ԫ�أ�û�и���Ԫ�ؿ��ܴ�����A[pa]~A[m]��B[pb]~B[n]��
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