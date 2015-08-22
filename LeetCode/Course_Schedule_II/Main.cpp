#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> result = vector<int>();
		vector<vector<int>> graph(numCourses, vector<int>());
		vector<int> counts(numCourses, 0);
		for (int i = 0; i<prerequisites.size(); ++i)
		{
			auto var = prerequisites[i];
			graph[var.second].push_back(var.first);
			counts[var.first]++;
		}
		queue<int> que;
		for (int i = 0; i < numCourses; ++i){
			if (counts[i] == 0){
				que.push(i);
				counts[i] = -1;
			}
		}
		set<int> finished = set<int>();
		while (!que.empty()){
			int cur = que.front();
			if (finished.find(cur) == finished.end()){
				result.push_back(cur);
				finished.insert(cur);
			}
			que.pop();
			for (int i = 0; i<graph[cur].size(); ++i){
				auto var = graph[cur][i];
				if (counts[var]>0) counts[var]--;
				if (counts[var] == 0) {
					que.push(var);
					counts[var] = -1;
				}
			}
		}
		for (int i = 0; i < numCourses; ++i){
			if (counts[i]>0) return vector<int>();
		}
		return result;
	}
};

int main(){
	pair<int, int> p1(3, 0);
	pair<int, int> p2(0, 1);
	vector<pair<int, int>> v1;
	v1.push_back(p1);
	v1.push_back(p2);
	Solution s;
	s.findOrder(4, v1);
}