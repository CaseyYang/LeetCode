#include<iostream>
#include<set>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	void check(vector<vector<char>> &board,int height,int width,int i,int j){
		queue<pair<int,int>> nQueue=queue<pair<int,int>>();
		pair<int,int> node=make_pair(i,j);
		nQueue.push(node);
		board[i][j]='E';
		while(!nQueue.empty()){
			pair<int,int> cur=nQueue.front();
			nQueue.pop();
			if(cur.second-1>0&&board[cur.first][cur.second-1]=='O'){
				board[cur.first][cur.second-1]='E';
				pair<int,int> left=make_pair(cur.first,cur.second-1);
				nQueue.push(left);
			}
			if(cur.second+1<width&&board[cur.first][cur.second+1]=='O'){
				board[cur.first][cur.second+1]='E';
				pair<int,int> right=make_pair(cur.first,cur.second+1);
				nQueue.push(right);
			}
			if(cur.first-1>0&&board[cur.first-1][cur.second]=='O'){
				board[cur.first-1][cur.second]='E';
				pair<int,int> up=make_pair(cur.first-1,cur.second);
				nQueue.push(up);
			}
			if(cur.first+1<height&&board[cur.first+1][cur.second]=='O'){
				board[cur.first+1][cur.second]='E';
				pair<int,int> down=make_pair(cur.first+1,cur.second);
				nQueue.push(down);
			}
		}
		return;
	}

    void solve(vector<vector<char>> &board) {
        if(board.size()==0||board[0].size()==0){
        	return;
        }
        else{
        	int height=board.size();
        	int width=board[0].size();
        	for(int i=0;i<height;++i){
        		if(board[i][width-1]=='O'){
        			check(board,height,width,i,width-1);
        		}
        		if(board[i][0]=='O'){
        			check(board,height,width,i,0);
        		}
        	}
        	for(int i=0;i<width;++i){
        		if(board[0][i]=='O'){
        			check(board,height,width,0,i);
        		}
        		if(board[height-1][i]=='O'){
        			check(board,height,width,height-1,i);
        		}
        	}
        	
        	for(int i=0;i<height;++i){
        		for(int j=0;j<width;++j){
        			if(board[i][j]=='O'){
        				board[i][j]='X';
        			}
        			if(board[i][j]=='E'){
        				board[i][j]='O';
        			}
        		}
        	}
        	return;
        }
    }
};

int main(){
	string Strs[]={"O"};
	vector<vector<char>> matrix=vector<vector<char>>();
	for(int i=0;i<1;++i){
		matrix.push_back(vector<char>());
		for(int j=0;j<Strs[i].size();++j){
			matrix.back().push_back(Strs[i][j]);
		}
	}
	Solution s;
	s.solve(matrix);
	cout<<matrix[0][0]<<endl;
	return 0;
}
