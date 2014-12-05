#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxArea(vector<int> &height) {
		if (height.size() == 0) return 0;
		int start = 0;
		int end = height.size() - 1;
		int contain = 0;
		while (start < end){
			int tmp = (end - start)*min(height[start], height[end]);
			if (tmp > contain) contain = tmp;
			if (height[start] < height[end]){
				int ts = start + 1;
				while (ts < end){
					if (height[ts] > height[start]) break;
					else ts += 1;
				}
				start = ts;
			}
			else{
				int ts = end - 1;
				while (ts > start){
					if (height[ts] > height[end]) break;
					else ts -= 1;
				}
				end = ts;
			}
		}
		return contain;
	}
};
int main(){
	return 0;
}