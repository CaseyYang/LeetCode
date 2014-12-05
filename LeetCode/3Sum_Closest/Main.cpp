#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void sort(vector<int> &num, int start, int end){
		if (start < end){
			int j = start - 1;
			for (int i = start; i < end; ++i){
				if (num[i] < num[end]){
					++j;
					swap(num[i], num[j]);
				}
			}
			++j;
			swap(num[j], num[end]);
			sort(num, start, j - 1);
			sort(num, j + 1, end);
		}
	}
	int threeSumClosest(vector<int> &num, int target) {
		if (num.size() == 0) return 0;
		sort(num, 0, num.size() - 1);
		int cur = 100000;
		for (int i = 0; i < num.size(); ++i){
			if (abs(target - cur) < num[i]) continue;
			for (int j = i + 1, k = num.size() - 1; j < k;){
				int tmp = num[i] + num[j] + num[k];
				cout << tmp << endl;
				if (abs(tmp - target) < abs(cur - target)){
					cur = tmp;
					if (cur == target) return cur;
				}
				if (tmp > target){
					--k;
				}
				else{
					++j;
				}
			}
		}
		return cur;
	}
};
int main(){
	vector<int> input;
	//1,2,4,8,16,32,64,128
	input.push_back(1);
	input.push_back(2);
	input.push_back(4);
	input.push_back(8);
	input.push_back(16);
	input.push_back(32);
	input.push_back(64);
	input.push_back(128);
	Solution s;
	cout<<s.threeSumClosest(input, 82)<<endl;
	return 0;
}