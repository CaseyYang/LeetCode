#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
		if (gas.size() > 0){
			int start = 0;
			int cur = 0;
			int oil = gas[0];
			bool change = false;
			do{
				oil -= cost[cur];
				if (oil >= 0){
					cur = (cur + 1 + gas.size()) % gas.size();
					if (cur == start){
						return start;
					}
					oil += gas[cur];
				}
				else{
					oil += cost[cur];
					oil += cost[start];
					oil -= gas[start];
					start = (start + 1 + gas.size()) % gas.size();
					if (start > cur){
						oil = gas[start];
						cur = start;
					}
					change = true;
				}
			} while (start != 0 || !change);
			return -1;
		}
		else{
			return -1;
		}
	}
	//更简洁的解法
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
		int sum = 0, total = 0;
		int startIndex = -1;
		for (int i = 0; i < gas.size(); ++i){
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0){
				startIndex = i;
				sum = 0;
			}
		}
		return total > 0 ? startIndex : 0;
	}
};

int main(){

}