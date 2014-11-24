#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	string getPermutation(int n, int k) {
		k = k - 1;
		vector<int> factorials = vector<int>(n + 1);
		factorials[0] = 1;
		factorials[1] = 1;
		for (int i = 2; i <= n; ++i){
			factorials[i] = factorials[i - 1] * i;
		}
		vector<int> elements = vector<int>();
		for (int i = 0; i <= n; ++i){
			elements.push_back(i);
		}
		int count = n;
		string s = "";
		while (count > 0){
			int element = k / factorials[count - 1] + 1;
			k = k - (element - 1)*factorials[count - 1];
			s.push_back('0' + elements[element]);
			elements.erase(elements.begin() + element);
			--count;
		}
		return s;
	}
	//string getPermutation(int n, int k) {
	//	string result;
	//	vector<int> factorials;
	//	vector<int> elements;
	//	for (int i = 0; i < n; i++) {
	//		if (!i) {
	//			factorials.push_back(1);
	//		}
	//		else {
	//			factorials.push_back(i * factorials[i - 1]);
	//		}
	//		elements.push_back(i + 1);
	//	}
	//	int position = 0;
	//	for (int i = n - 1; i > -1; i--) {
	//		position = (k - 1) / factorials[i];
	//		k = k - position * factorials[i];
	//		result.push_back('0' + elements[position]);
	//		elements.erase(elements.begin() + position);
	//	}
	//	return result;
	//}
};
int main(){
	Solution s;
	string result = s.getPermutation(3, 1);
	cout << result << endl;
	return 0;
}