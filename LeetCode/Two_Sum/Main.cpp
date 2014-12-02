#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	void swap(int &a, int &b){
		int tmp = b;
		b = a;
		a = tmp;
	}
	void sort(vector<int> &numbers, int start, int end){
		if (start < end){
			int j = start - 1;
			for (int i = start; i < end - 1; ++i){
				if (numbers[i] < numbers[end]){
					++j;
					swap(numbers[i], numbers[j]);
				}
			}
			++j;
			swap(numbers[j], numbers[end]);
			sort(numbers, start, j - 1);
			sort(numbers, j + 1, end);
		}
	}
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> s = map<int, int>();
		for (int i = 0; i < numbers.size(); ++i){
			s[numbers[i]] += 1;
		}
		int index1 = -1, index2 = -1;
		for (int i = 0; i < numbers.size(); ++i){
			int other = target - numbers[i];
			if (s.find(other) != s.end()){
				if (other == numbers[i]){
					if (s[numbers[i]] >= 2){
						if (index1 == -1) index1 = i;
						else{
							index2 = i;
							break;
						}
					}
				}
				else{
					if (index1 == -1) index1 = i;
					else{
						index2 = i;
						break;
					}
				}
			}
		}
		vector<int> result = vector<int>();
		result.push_back(index1 + 1);
		result.push_back(index2 + 1);
		return result;
	}
};
int main(){

}