#include<iostream>
#include<vector>
#include<set>
#include<math.h>
using namespace std;

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (k == 0) return false;
		multiset<int> ms;
		for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter){
			multiset<int>::iterator smallest = ms.lower_bound(*iter - t);
			if (smallest!=ms.end() && abs(*smallest - *iter) <= t){
				return true;
			}
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
}