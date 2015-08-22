#include<iostream>
using namespace std;

class Solution {
public:
	int length(int a, int b, int c, int d){
		if (c < a){
			swap(a, c);
			swap(b, d);
		}
		if (b >= d) return d - c;
		if (b >= c) return b - c;
		return -1;
	}
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int l1 = length(A, C, E, G);
		int l2 = length(B, D, F, H);
		if (l1 <= 0 || l2 <= 0) return (C - A)*(D - B) + (G - E)*(H - F);
		return (C - A)*(D - B) + (G - E)*(H - F)-l1*l2;
	}
};

int main(){
	return 0;
}