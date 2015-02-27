#include<iostream>
using namespace std;

const int N = 6;
void func(){
	int A[] = { 1, 1, 1, 0, 0, 1, 1 };
	int num[2 * N + 1];
	int count[2] = { 0, 0 }, maxlen = 0, currlen = 0;
	for (int i = 0; i < 2 * N + 1; ++i) num[i] = -2;
	num[N] = -1;
	for (int i = 0; i < N; ++i)
	{
		count[A[i]] += 1;
		int diff = count[1] - count[0] + N;
		if (num[diff] == -2)//尚不存在，B的下标是差，值是A的下标 
			num[diff] = i;
		else//already exist
		{
			currlen = i - num[diff]; //num[ B[i] + N ]是B[i]已存在的下标
			if (currlen > maxlen)
				maxlen = currlen;
		}
	}
	cout << maxlen << endl;
}