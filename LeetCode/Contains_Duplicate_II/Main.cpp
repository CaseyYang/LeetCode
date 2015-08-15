#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (k == 0) return false;
		multiset<int> ms = multiset<int>();
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter){
			if (ms.find(*iter) != ms.end()) return true;
			else{
				if (ms.size() == k){
					multiset<int>::iterator rmIter = ms.find(*(iter - k));
					ms.erase(rmIter);
				}
				ms.insert(*iter);
			}
		}
		return false;
	}
};

int main(){
	vector<int> v = vector<int>();
	v.push_back(10);
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	multiset<int> ms = multiset<int>(v.begin(),v.end());
	cout << ms.size() << endl;
	ms.erase(10);
	cout << ms.size() << endl;
}