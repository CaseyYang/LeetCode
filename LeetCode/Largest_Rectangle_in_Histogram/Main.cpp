#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		if (height.size() == 0) return 0;
		int res = 0;
		vector<int> tmp = height;
		tmp.push_back(0);  // Important
		stack<int> s;
		for (int i = 0; i < tmp.size(); i++)
		{
			cout << "i=" << i << endl;
			if (s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) s.push(i);
			else{
				while (!s.empty() && tmp[s.top()] > tmp[i])
				{
					int idx = s.top(); s.pop();
					int width = s.empty() ? i : (i - s.top() - 1);
					res = max(res, tmp[idx] * width);
					cout << idx<<", "<<res << endl;
				}
				s.push(i);  // Important
			}
		}
		return res;
	}
};
//class Solution {
//public:
//	int largestRectangleArea(vector<int> &height) {
//		if (height.size() == 0) return 0;
//		if (height.size() == 1) return height[0];
//		int area = 0;
//		vector<int> tmp = height;
//		tmp.push_back(0);
//		stack<int> s;
//		int curHeight = 0;
//		int maxArea = 0;
//		for (int i = 0; i < tmp.size(); ++i){
//			if (tmp[i] < curHeight){
//				cout <<"i="<< i << endl;
//				int length = 1;
//				while (!s.empty()){
//					int topHeight = s.top();
//					if (topHeight >= tmp[i]){
//						s.pop();
//						area = topHeight*length;
//						++length;
//						if (area > maxArea){
//							maxArea = area;
//							cout << maxArea << endl;
//						}
//					}
//					else{
//						break;
//					}
//				}
//			}
//			if (i < height.size()){
//				s.push(height[i]);
//				curHeight = height[i];
//			}
//		}
//		return maxArea;
//	}
//};
int main(){
	vector<int> heights = vector<int>();
	heights.push_back(2);
	heights.push_back(7);
	heights.push_back(5);
	heights.push_back(6);
	heights.push_back(4);
	Solution s;
	cout << s.largestRectangleArea(heights) << endl;

	return 0;
}