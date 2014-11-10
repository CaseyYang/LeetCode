#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		int result = 0;
		unordered_set<int> is = unordered_set<int>();
		for (int i = 0; i < num.size(); ++i){
			is.insert(num[i]);
		}
		while (!is.empty() || is.size() > result){
			int center = 0;
			for (unordered_set<int>::iterator iter = is.begin(); iter != is.end(); ++iter){
				center = *iter;
				break;
			}
			is.erase(center);
			bool left = true;
			bool right = true;
			int length = 1;
			for (int i = 1; i < num.size(); ++i){
				if (left&&is.find(center - i) != is.end()){
					is.erase(center - i);
					++length;
				}
				else{
					left = false;
				}
				if (right&&is.find(center + i) != is.end()){
					is.erase(center + i);
					++length;
				}
				else{
					right = false;
				}
				if (!left&&!right){
					break;
				}
			}
			result = length>result ? length : result;
		}
		return result;
	}
};

int main(){
	vector<int> num = vector<int>();
	num.push_back(100);
	num.push_back(4);
	num.push_back(200);
	num.push_back(1);
	num.push_back(3);
	num.push_back(2);
	Solution s;
	cout<<s.longestConsecutive(num)<<endl;
	return 0;
}