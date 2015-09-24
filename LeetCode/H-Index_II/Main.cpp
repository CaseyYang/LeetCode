#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.size() == 0) return 0;
		int current = 0;
		for (int i = citations.size() - 1; i >= 0; --i){
			if (citations[i] >= citations.size() - i){
				current = citations.size() - i;
				continue;
			}
			else{
				return current;
			}
		}
		return min(citations[0], (int)citations.size());
	}
};