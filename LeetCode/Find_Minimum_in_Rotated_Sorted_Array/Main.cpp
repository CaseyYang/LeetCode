#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	Solution(){};
	int findMin(vector<int> &num) {
		if (num.size() > 0){
			int start = 0;
			int end = num.size() - 1;
			while (num[start] > num[end] && start + 1 < end){
				int middle = (start + end) / 2;
				if (num[start] < num[middle]){
					start = middle;
				}
				if (num[middle] < num[end]){
					end = middle;
				}
			}
			return num[end];
		}
	}
};

int main(){
	Solution s;
	vector<int> v = vector<int>();
	//int i[7] = { 4, 5, 6, 7, 0, 1, 2 };
	int i[1] = { 4};
	for (int j = 0; j < 1; ++j){
		v.push_back(i[j]);
	}
	cout<<s.findMin(v)<<endl;
	return 0;
}