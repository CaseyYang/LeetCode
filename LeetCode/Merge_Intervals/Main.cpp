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
	void swap(Interval &i1, Interval &i2){
		int tmp = i1.start;
		i1.start = i2.start;
		i2.start = tmp;
		tmp = i1.end;
		i1.end = i2.end;
		i2.end = tmp;
	}
	void qsort(vector<Interval> &intervals, int start, int end){
		if (start < end){
			int j = start - 1;
			for (int i = start; i < end; ++i){
				if (intervals[i].start < intervals[end].start){
					j++;
					swap(intervals[i], intervals[j]);					
				}
			}
			j++;
			swap(intervals[j], intervals[end]);
			qsort(intervals, start, j - 1);
			qsort(intervals, j + 1, end);
		}
	}
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> result = vector<Interval>();
		if (intervals.size() == 0) return result;
		qsort(intervals, 0, intervals.size() - 1);
		int endd = intervals[0].end;
		result.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i){
			if (intervals[i].start <= endd){
				result.back().end = max(intervals[i].end, endd);
			}
			else{
				result.push_back(intervals[i]);
			}
			endd = result.back().end;
		}
		return result;
	}
};