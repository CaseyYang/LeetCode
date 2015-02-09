#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int calculateMinimumHP(vector<vector<int> > &dungeon) {
		if (dungeon.size() == 0 || dungeon[0].size() == 0) return 0;
		dungeon[dungeon.size() - 1][dungeon[0].size() - 1] = max(0 - dungeon[dungeon.size() - 1][dungeon[0].size() - 1], 0);
		for (int i = dungeon.size() - 2; i >= 0; --i){
			dungeon[i][dungeon[0].size() - 1] = max(dungeon[i + 1][dungeon[0].size() - 1] - dungeon[i][dungeon[0].size() - 1], 0);
		}
		for (int j = dungeon[0].size() - 2; j >= 0; --j){
			dungeon[dungeon.size() - 1][j] = max(dungeon[dungeon.size() - 1][j + 1] - dungeon[dungeon.size() - 1][j], 0);
		}
		for (int i = dungeon.size() - 2; i >= 0; --i){
			for (int j = dungeon[0].size() - 2; j >= 0; --j){
				dungeon[i][j] = max(min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j], 0);
			}
		}
		return 1 + dungeon[0][0];
	}
};
int main(){
	return 0;
}