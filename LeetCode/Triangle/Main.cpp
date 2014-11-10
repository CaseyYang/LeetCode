#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>> &triangle) {
		if (triangle.size() == 0){
			return 0;
		}
		else{
			if (triangle.size() == 1){
				return triangle[0][0];
			}
			else{
				vector<int> pre = triangle[0];
				vector<int> cur;
				for (int i = 1; i < triangle.size(); ++i){
					cur = vector<int>();
					for (int j = 0; j < triangle[i].size(); ++j){
						if (j == 0){
							cur.push_back(pre[j] + triangle[i][0]);
							continue;
						}
						if (j == triangle[i].size() - 1){
							cur.push_back(pre[j - 1] + triangle[i].back());
							continue;
						}
						else{
							cur.push_back(min(pre[j - 1], pre[j]) + triangle[i][j]);
							continue;
						}
					}
					pre = cur;
					
				}
				int max = pre[0];
				for (int i = 1; i < pre.size(); ++i){
					max = pre[i] < max ? pre[i] : max;
				}
				return max;
			}
		}
	}
};

int main(){
	vector<int> a = vector<int>();
	a.push_back(1);
	vector<int> b = vector<int>();
	b.push_back(2);
	b.push_back(3);
	vector<vector<int>> c = vector<vector<int>>();
	c.push_back(a);
	c.push_back(b);
	Solution s;
	s.minimumTotal(c);
	return 0;
}