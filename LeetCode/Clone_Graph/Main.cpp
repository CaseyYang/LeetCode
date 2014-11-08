#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL){
			return NULL;
		}
		else{
			auto nodeMap = map<UndirectedGraphNode*, UndirectedGraphNode*>();
			auto newHead = new UndirectedGraphNode(node->label);
			nodeMap[node] = newHead;
			auto nQueue = queue<UndirectedGraphNode*>();
			nQueue.push(node);
			while (!nQueue.empty()){
				auto cur = nQueue.front();
				nQueue.pop();
				if (nodeMap.find(cur) == nodeMap.end()){
					auto newCur = new UndirectedGraphNode(cur->label);
					nodeMap[cur] = newCur;
				}
				for (int i = 0; i < cur->neighbors.size(); ++i){
					if (nodeMap.find(cur->neighbors[i]) == nodeMap.end()){
						nQueue.push(cur->neighbors[i]);
					}
				}
			}
			for (auto iter = nodeMap.begin(); iter != nodeMap.end(); ++iter){
				auto cur = iter->first;
				auto newCur = iter->second;
				for (int i = 0; i < cur->neighbors.size(); ++i){
					newCur->neighbors.push_back(nodeMap[cur->neighbors[i]]);
				}
			}
			return newHead;
		}
	}
};

int main(){

}