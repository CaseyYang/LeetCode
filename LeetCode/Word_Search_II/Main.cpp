#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
using namespace std;

typedef pair<int, int> Node;

//注意：代码逻辑应该是正确的，但是在使用大数据集测试时会超时。
//要通过大数据测试，需要使用Trie树。
class Solution {
public:
	bool recursion(vector<vector<char>>& board, string &word, int index, Node &curNode, set<Node> &s) {
		bool found = false;
		vector<Node> canadidateNodes = vector<Node>();
		if (curNode.first - 1 >= 0 && board[curNode.first - 1][curNode.second] == word[index]) {
			Node nextNode = make_pair(curNode.first - 1, curNode.second);
			if (s.find(nextNode) == s.end()) {
				canadidateNodes.push_back(nextNode);
			}
		}
		if (curNode.first + 1 < board.size() && board[curNode.first + 1][curNode.second] == word[index]) {
			Node nextNode = make_pair(curNode.first + 1, curNode.second);
			if (s.find(nextNode) == s.end()) {
				canadidateNodes.push_back(nextNode);
			}
		}
		if (curNode.second - 1 >= 0 && board[curNode.first][curNode.second - 1] == word[index]) {
			Node nextNode = make_pair(curNode.first, curNode.second - 1);
			if (s.find(nextNode) == s.end()) {
				canadidateNodes.push_back(nextNode);
			}
		}
		if (curNode.second + 1 < board[curNode.first].size() && board[curNode.first][curNode.second + 1] == word[index]) {
			Node nextNode = make_pair(curNode.first, curNode.second + 1);
			if (s.find(nextNode) == s.end()) {
				canadidateNodes.push_back(nextNode);
			}
		}
		if (canadidateNodes.size() == 0) return false;
		for (int i = 0; i < canadidateNodes.size(); ++i) {
			if (index + 1 == word.size()) {
				return true;
			}
			s.insert(canadidateNodes[i]);
			if (recursion(board, word, index + 1, canadidateNodes[i], s)) {
				return true;
			}
			s.erase(canadidateNodes[i]);
		}
		return false;
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		set<string> result = set<string>();
		for (int i = 0; i < words.size(); ++i) {
			set<Node> s = set<Node>();
			bool found = false;
			for (int x = 0; x < board.size(); ++x) {
				for (int y = 0; y < board[x].size(); ++y) {
					if (board[x][y] == words[i][0]) {
						Node tmpNode = make_pair(x, y);
						if (1 == words[i].size()) {
							found = true;
							break;
						}
						s.insert(tmpNode);
						if (recursion(board, words[i], 1, tmpNode, s)) {
							found = true;
							break;
						}
						s.erase(tmpNode);
					}
				}
				if (found) break;
			}
			if (found) {
				cout << words[i] << endl;
				result.insert(words[i]);
			}
		}
		vector<string> result2 = vector<string>(result.begin(), result.end());
		return result2;
	}
};

int main() {
	vector<vector<char>> board = { {'a','b'},{'a','a'} };
	vector<string> words = { "aaba" };
	Solution s;
	s.findWords(board, words);
}