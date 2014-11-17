#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		if (height.size() == 0) return 0;
		if (height.size() == 1) return height[0];
		height.push_back(0);
		stack<int> indexStack;
		int maxArea = 0;
		for (int i = 0; i < height.size(); ++i){
			if (!indexStack.empty() && height[indexStack.top()] > height[i]){
				while (!indexStack.empty() && height[indexStack.top()] > height[i]){
					int index = indexStack.top();
					indexStack.pop();
					int area;
					if (!indexStack.empty()){
						area = height[index] * (i - indexStack.top() - 1);
					}
					else{
						area = height[index] * i;
					}
					//cout << area << endl;
					maxArea = area > maxArea ? area : maxArea;
				}
			}
			indexStack.push(i);
		}
		return maxArea;
	}
};
int main(){
	vector<int> input = vector<int>();
	//input.push_back(1);
	//input.push_back(1);
	input.push_back(2);
	input.push_back(7);
	input.push_back(5);
	input.push_back(6);
	input.push_back(4);
	Solution s;
	cout << s.largestRectangleArea(input) << endl;
	return 0;
}