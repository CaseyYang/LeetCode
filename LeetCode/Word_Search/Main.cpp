#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	set<pair<int, int>> visited;
	bool result = false;
	bool DFS(vector<vector<char>> &board, pair<int, int> &coordinate, string &word, int index){
		if (index == word.size()){
			result = true;
			return true;
		}
		for (int i = 0; i < 4; ++i){
			pair<int, int>newCoordinate = make_pair<int, int>(0, 0);
			if (i == 0){
				if (coordinate.first > 0){
					newCoordinate.first = coordinate.first - 1;
					newCoordinate.second = coordinate.second;
				}
				else{
					continue;
				}
			}
			if (i == 1){
				if (coordinate.first < board.size() - 1){
					newCoordinate.first = coordinate.first + 1;
					newCoordinate.second = coordinate.second;
				}
				else{
					continue;
				}
			}
			if (i == 2){
				if (coordinate.second > 0){
					newCoordinate.first = coordinate.first;
					newCoordinate.second = coordinate.second - 1;
				}
				else{
					continue;
				}
			}
			if (i == 3){
				if (coordinate.second < board[0].size() - 1){
					newCoordinate.first = coordinate.first;
					newCoordinate.second = coordinate.second + 1;
				}
				else{
					continue;
				}
			}
			if (visited.find(newCoordinate) == visited.end() && board[newCoordinate.first][newCoordinate.second] == word[index]){
				visited.insert(newCoordinate);
				if (DFS(board, newCoordinate, word, index + 1)){
					return true;
				}
				visited.erase(newCoordinate);
			}
		}
		return false;
	}
	bool exist(vector<vector<char> > &board, string word) {
		for (int i = 0; i < board.size(); ++i){
			for (int j = 0; j < board[i].size(); ++j){
				if (board[i][j] == word[0]){
					visited = set<pair<int, int>>();
					pair<int, int> start = make_pair(i, j);
					visited.insert(start);
					if (DFS(board, start, word, 1)){
						return true;
					}
				}
			}
		}
		return result;
	}
};
int main(){
	vector<vector<char>> input;
	input.push_back(vector<char>());
	input[0].push_back('b');
	input[0].push_back('a');
	Solution s;
	cout << s.exist(input, "ab") << endl;
	return 0;
}