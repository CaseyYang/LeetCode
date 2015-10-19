#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<utility>
using namespace std;

struct NeighNode {
	int gIndex;
	NeighNode* neighbor;
};
struct GraphNode {
	int value;
	NeighNode *neighbor;
};

vector<pair<int,int>> func(vector<GraphNode> &graph, int startNode) {
	vector<pair<int,int>> result = vector<pair<int, int>>();
	queue<GraphNode> q = queue<GraphNode>();
	set<int> t = set<int>();
	q.push(graph[startNode]);
	t.insert(graph[startNode].value);
	while (!q.empty()) {
		GraphNode tmpNode = q.front();
		NeighNode* pt = tmpNode.neighbor;
		while (pt != NULL) {
			if (t.find(graph[pt->gIndex].value) == t.end()) {
				q.push(graph[pt->gIndex]);
				t.insert(graph[pt->gIndex].value);
			}
			else {
				result.push_back(make_pair(tmpNode.value, graph[pt->gIndex].value));
			}
		}
	}
	return result;
}