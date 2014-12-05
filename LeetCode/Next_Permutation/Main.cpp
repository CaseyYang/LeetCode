#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		int minIndex = -1;
		int newStart = -1;
		for (int i = num.size() - 1; i > 0; --i){
			if (minIndex == -1 || num[i] < num[minIndex]){
				minIndex = i;
			}
			if (num[i] > num[i - 1]){
				int cur = INT_MAX;
				for (int j = num.size() - 1; j >= i; --j){
					if (num[j] > num[i - 1] && num[j] < cur){
						cur = num[j];
						minIndex = j;
					}
				}
				swap(num[i - 1], num[minIndex]);
				newStart = i;
				break;
			}
		}
		if (newStart == -1) {
			swap(num[0], num[num.size() - 1]);
			newStart = 0;
		}
		sort(num.begin() + newStart, num.end());
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