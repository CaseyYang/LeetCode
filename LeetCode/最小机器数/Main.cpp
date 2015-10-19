#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

struct Project {
	int start;
	int end;
};

bool ProjectCompare(const Project& p1, const Project& p2) {
	return p1.start < p2.start;
}

int func(vector<Project> &projects) {
	sort(projects.begin(), projects.end(), ProjectCompare);
	priority_queue<int,vector<int>,greater<int> > pq;
	int maxResult = 0;
	for (vector<Project>::iterator iter = projects.begin(); iter != projects.end(); ++iter) {
		pq.push(iter->end);
		while (pq.top() < iter->start) {
			pq.pop();
		}
		maxResult = maxResult > pq.size() ? maxResult : pq.size();
	}
	return maxResult;
}

int main() {
	return 0;
}