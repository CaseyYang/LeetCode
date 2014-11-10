#include<iostream>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<string> q = queue<string>();
		q.push(start);
		q.push("#");
		int layer = 1;
		while (!q.empty()){
			string curStr = q.front();
			q.pop();
			if (curStr == "#"){
				if (q.empty()){
					return 0;
				}
				else{
					++layer;
					q.push("#");
				}				
			}
			else{
				if (dict.find(curStr) != dict.end()){
					dict.erase(curStr);
				}
				for (int i = 0; i < curStr.length(); ++i){
					char curChar = curStr[i];
					for (int j = 0; j < 26; ++j){
						if ('a' + j != curChar){
							curStr[i] = 'a' + j;
							if (curStr == end){
								return (layer + 1);
							}
							else{
								if (dict.find(curStr) != dict.end()){
									q.push(curStr);
									dict.erase(curStr);
								}
							}
						}
					}
					curStr[i] = curChar;
				}
			}
		}
		return 0;
	}
};

int main(){
	string start = "hot";
	string end = "dog";
	unordered_set<string> dict = unordered_set<string>();
	dict.insert("hot");
	dict.insert("dog");
	dict.insert("dot");
	Solution s;
	cout<<s.ladderLength(start, end, dict)<<endl;
	return 0;
}