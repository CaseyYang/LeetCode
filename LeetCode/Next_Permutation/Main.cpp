#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void Recursion(vector<int> &num, int end){
		bool changed = true;
		for (int i = num.size() - 1; i > end;){
			if (num[i] > num[i - 1]){
				swap(num[i - 1], num[num.size() - 1]);
				return Recursion(num, i);
			}
			else{
				--i;
			}
		}
		swap(num[end], num[num.size() - 1]);
		return;
	}
	void nextPermutation(vector<int> &num) {
		Recursion(num,0);
	}
};
int main(){
	vector<int> input;
	//input.push_back(1);
	//input.push_back(2);
	//input.push_back(7);
	//input.push_back(6);
	//input.push_back(5);
	input.push_back(1);
	input.push_back(1);
	input.push_back(5);
	Solution s;
	s.nextPermutation(input);
	for (int i = 0; i < input.size(); ++i) cout << input[i] << " ";
	return 0;
}