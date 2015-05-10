#include<iostream>
#include<list>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		if (n==1||n == 0) return 0;
		if (n <= 3) return n-2;
		int *canadidates = new int[n+1];
		for (int i = 0; i <= n; ++i){
			canadidates[i] = i;
		}
		int count = n - 2;
		for (int i = 2; i < n; ++i){
			if (canadidates[i] == 0) continue;
			for (int j = i*i; j < n; j += i){//2 tricks
				if (canadidates[j] != 0){
					canadidates[j] = 0;
					--count;
				}
			}
			if (canadidates[i]*canadidates[i] >= n){//trick
				break;
			}
		}
		return count;
	}
};

int main(){
	Solution s;
	cout<<s.countPrimes(5);
	return 0;
}