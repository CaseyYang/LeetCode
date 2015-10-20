#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

bool check(vector<vector<int>> &graph) {
	return false;
}

typedef pair<int, int> Node;

int func(vector<vector<int>> &graph, int xIndex, int yIndex) {
	int width = graph.size();
	int length = graph[0].size();
	int count = 0;
	while (!check(graph)) {
		queue<Node> q;
		q.push(make_pair(xIndex, yIndex));
		while (!q.empty()) {
			Node node = q.front();
			q.pop();
			if (node.first - 1 >= 0 && graph[node.first - 1][node.second] == graph[node.first][node.second]) {
				q.push(make_pair(node.first - 1, node.second));
			}
			if (node.first + 1 < length && graph[node.first + 1][node.second] == graph[node.first][node.second]) {
				q.push(make_pair(node.first + 1, node.second));
			}
			if (node.second - 1 >= 0 && graph[node.first][node.second - 1] == graph[node.first][node.second]) {
				q.push(make_pair(node.first, node.second - 1));
			}
			if (node.second + 1 >= 0 && graph[node.first][node.second + 1] == graph[node.first][node.second]) {
				q.push(make_pair(node.first, node.second + 1));
			}
			graph[node.first][node.second] = 1 - graph[node.first][node.second];
		}
		count++;
	}
	return count;
}

void main() {
	vector<int> v = vector<int>(5);
	cout << v.size() << endl;
}