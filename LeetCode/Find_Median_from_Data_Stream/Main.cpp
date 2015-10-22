#include<iostream>
#include<queue>
#include<functional>
using namespace std;

class MedianFinder {
public:
	priority_queue<int, vector<int>, greater<int> > min_h;
	priority_queue<int, vector<int>> max_h;
	// Adds a number into the data structure.
	void addNum(int num) {
		if (min_h.size() == max_h.size() && min_h.size() == 0) {
			min_h.push(num);
			return;
		}
		if (max_h.size() == 0) {
			if (num > min_h.top()) {
				max_h.push(min_h.top());
				min_h.pop();
				min_h.push(num);
			}
			else {
				max_h.push(num);
			}
			return;
		}
		if (num <= max_h.top()) {
			max_h.push(num);
			if (max_h.size() > min_h.size() + 1) {
				min_h.push(max_h.top());
				max_h.pop();
			}
		}
		else {
			if (num >= min_h.top()) {
				min_h.push(num);
				if (min_h.size()>max_h.size()) {
					max_h.push(min_h.top());
					min_h.pop();
				}
			}
			else {
				if (min_h.size() < max_h.size()) min_h.push(num);
				else {
					max_h.push(num);
				}
			}
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if (min_h.size() > 0 && min_h.size() == max_h.size()) return (max_h.top() + min_h.top()) / 2.0;
		else {
			if (min_h.size() == 0 && max_h.size() == 0) return 0;
			else {
				if (min_h.size() == 0 || max_h.size() == 0) return min_h.size() == 0 ? max_h.top() : min_h.top();
				else {
					cout << "here!" << endl;
					return max_h.top();
				}
			}
		}
	}
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
void main() {
	 MedianFinder mf;
	 mf.addNum(1);
	 mf.addNum(2);
	 mf.addNum(3);
	 cout<<mf.findMedian()<<endl;
}