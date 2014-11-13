#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct Node{
	int key;
	int val;
	int used;
	void swap(Node &n1, Node &n2){
		int tmp = n2.val;
		n2.val = n1.val;
		n1.val = tmp;
		tmp = n2.key;
		n2.key = n1.key;
		n1.key = tmp;
		tmp = n2.used;
		n2.used = n1.used;
		n1.used = tmp;
	}
};
class LRUCache{
public:
	vector<Node> nodes;
	map<int, int> m;
	int size;
	int capacity;
	LRUCache(int capacity) {
		nodes = vector<Node>(capacity);
		m = map<int, int>();
		size = 0;
		this->capacity = capacity;
	}
	int get(int key) {
		if (m.find(key) != m.end()){
			for (int i = 0; i < nodes.size(); ++i){
				if (nodes[i].key == key){
					nodes[i].used += 1;
					//buildHeap();
					break;
				}
			}
			return m[key];
		}
		return -1;
	}
	void set(int key, int value) {
		if (size == capacity){
			buildHeap();
			m.erase(nodes[0].key);
			nodes[0].key = key;
			nodes[0].val = value;
			nodes[0].used = 0;
			m[key] = value;
		}
		else{
			nodes[size].key = key;
			nodes[size].val = value;
			nodes[size].used = 0;
			m[key] = value;
			++size;
		}
	}
	void heapAdjust(int root, int size){
		int left = root * 2;
		int right = root * 2 + 1;
		int change = root;
		if (left < size && nodes[root].used > nodes[left].used){
			change = left;
		}
		if (right < size && nodes[change].used > nodes[right].used){
			change = right;
		}
		if (change != root){
			swap(nodes[root], nodes[change]);
			heapAdjust(change, size);
		}
	}
	void buildHeap(){
		for (int i = size / 2; i >= 0; --i){
			heapAdjust(i, size);
		}
	}
};
int main(){
	return 0;
}