#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
	int x, y;
	char element;
	bool visited;
	Node(){
		this->x = this->y = -1;
		this->element = '2';
		this->visited = false;
	}
	Node(int x, int y, char element){
		this->x = x;
		this->y = y;
		this->element = element;
		this->visited = false;
	}
};

class Solution {
public:
	int numIslands(vector<vector<char>> &grid) {
		vector<vector<Node>> nodes = vector<vector<Node>>();
		int count = 0;
		for (int i = 0; i < grid.size(); ++i){
			nodes.push_back(vector<Node>());
			for (int j = 0; j < grid[i].size(); ++j){
				nodes[i].push_back(Node(i, j, grid[i][j]));
			}
		}
		int maxX = grid.size();
		int maxY = 0;
		if (maxX > 0){
			maxY = grid[0].size();
		}
		else{
			return 0;
		}
		for (int i = 0; i < grid.size(); ++i){
			for (int j = 0; j < grid[i].size(); ++j){
				if (nodes[i][j].element == '1'&&!nodes[i][j].visited){
					queue<Node> q = queue<Node>();
					q.push(nodes[i][j]);
					while (!q.empty()){
						Node curNode = q.front();
						q.pop();
						if (curNode.x - 1 >= 0 && nodes[curNode.x - 1][curNode.y].element == '1'&&!nodes[curNode.x - 1][curNode.y].visited){
							nodes[curNode.x - 1][curNode.y].visited = true;
							q.push(nodes[curNode.x - 1][curNode.y]);
						}
						if (curNode.x + 1 < maxX && nodes[curNode.x + 1][curNode.y].element == '1'&&!nodes[curNode.x + 1][curNode.y].visited){
							nodes[curNode.x + 1][curNode.y].visited = true;
							q.push(nodes[curNode.x + 1][curNode.y]);
						}
						if (curNode.y - 1 >= 0 && nodes[curNode.x][curNode.y - 1].element == '1'&&!nodes[curNode.x][curNode.y - 1].visited){
							nodes[curNode.x][curNode.y - 1].visited = true;
							q.push(nodes[curNode.x][curNode.y - 1]);
						}
						if (curNode.y + 1 < maxY && nodes[curNode.x][curNode.y + 1].element == '1'&&!nodes[curNode.x][curNode.y + 1].visited){
							nodes[curNode.x][curNode.y + 1].visited = true;
							q.push(nodes[curNode.x][curNode.y + 1]);
						}
					}
					++count;
				}
			}
		}
		return count;
	}
};

int main(){
	return 0;
}