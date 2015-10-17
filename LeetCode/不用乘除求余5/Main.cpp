#include<iostream>
using namespace std;

int func(int n) {
	cout << n << " ";
	int d = 5;
	while (d < n) {
		d = d << 1;
	}
	while (n >= 5) {
		while (d > n) {
			d = d >> 1;
		}
		n = n - d;
	}
	return n;
}

int main() {
	cout << func(0)<<endl;
	cout << func(1) << endl;
	cout << func(2) << endl;
	cout << func(3) << endl;
	cout << func(4) << endl;
	cout << func(5) << endl;
	cout << func(6) << endl;
	cout << func(50) << endl;
	cout << func(99) << endl;
	cout << func(1000001) << endl;
}