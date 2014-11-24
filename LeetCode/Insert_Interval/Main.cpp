#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result = vector<Interval>();
		bool insert = false;
		for (int i = 0; i < intervals.size(); ++i){
			if (intervals[i].end < newInterval.start){
				result.push_back(intervals[i]);
				continue;
			}
			if (intervals[i].start > newInterval.end){
				if (!insert){
					result.push_back(newInterval);
					insert = true;
				}
				result.push_back(intervals[i]);
				continue;
			}
			else{
				Interval tmp(min(intervals[i].start, newInterval.start), max(intervals[i].end, newInterval.end));
				insert = true;
				result.push_back(tmp);
				int endd = tmp.end;
				for (int j = i + 1; j < intervals.size(); ++j){
					if (intervals[j].start <= endd){
						result.back().end = max(endd, intervals[j].end);
						endd = result.back().end;
					}
					else{
						result.push_back(intervals[j]);
					}
				}
				break;
			}
		}
		if (!insert) result.push_back(newInterval);
		return result;
	}
};
int main(){

}