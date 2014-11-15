#include<iostream>
#include<list>
#include<map>
using namespace std;
struct Node{
	int key;
	int val;
	int used;
	Node(int key, int val) :key(key), val(val){}
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
	list<Node> nodes;
	map<int, list<Node>::iterator> m;
	int size;
	int capacity;
	LRUCache(int capacity) {
		nodes = list<Node>();
		m = map<int, list<Node>::iterator>();
		size = 0;
		this->capacity = capacity;
	}
	int get(int key) {
		if (m.find(key) != m.end()){
			list<Node>::iterator iter = m[key];
			int tmpKey = iter->key;
			int tmpVal = iter->val;
			nodes.erase(iter);
			nodes.push_front(Node(tmpKey, tmpVal));
			m[key] = nodes.begin();
			return m[key]->val;
		}
		return -1;
	}
	void set(int key, int value) {
		if (m.find(key) == m.end()){
			if (size == capacity){
				m.erase(nodes.back().key);
				nodes.pop_back();
			}
			else{
				++size;
			}
			nodes.push_front(Node(key, value));
			m[key] = nodes.begin();
		}
		else{
			m[key]->val = value;
			get(key);
		}
	}
	//void heapAdjust(int root, int size){
	//	int left = root * 2;
	//	int right = root * 2 + 1;
	//	int change = root;
	//	if (left < size && nodes[root].used > nodes[left].used){
	//		change = left;
	//	}
	//	if (right < size && nodes[change].used > nodes[right].used){
	//		change = right;
	//	}
	//	if (change != root){
	//		swap(nodes[root], nodes[change]);
	//		heapAdjust(change, size);
	//	}
	//}
	//void buildHeap(){
	//	for (int i = size / 2; i >= 0; --i){
	//		heapAdjust(i, size);
	//	}
	//}
};
int main(){
	return 0;
}