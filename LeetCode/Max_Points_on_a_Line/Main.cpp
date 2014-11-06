#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	void swap(Point &p1, Point &p2){
		int tmp = p1.x;
		p1.x = p2.x;
		p2.x = tmp;
		tmp = p1.y;
		p1.y = p2.y;
		p2.y = tmp;
	}
	void quickSortForX(vector<Point> &points, int start, int end){
		if (start < end){
			swap(points[(start + end) / 2], points[end]);
			int j = start - 1;
			for (int i = start; i < end; ++i){
				if (points[i].x < points[end].x){
					++j;
					swap(points[i], points[j]);
				}
			}
			++j;
			swap(points[end], points[j]);
			quickSortForX(points, start, j - 1);
			quickSortForX(points, j + 1, end);
		}
	}
	void quickSortForY(vector<Point> &points, int start, int end){
		if (start < end){
			swap(points[(start + end) / 2], points[end]);
			int j = start - 1;
			for (int i = start; i < end; ++i){
				if (points[i].y < points[end].y){
					++j;
					swap(points[i], points[j]);
				}
			}
			++j;
			swap(points[end], points[j]);
			quickSortForX(points, start, j - 1);
			quickSortForX(points, j + 1, end);
		}
	}
	int maxPoints3(vector<Point> &points) {
		if (points.size() > 0){
			quickSortForX(points, 0, points.size() - 1);
			int max = 0;
			int cur = points[0].x;
			int curCount = 0;
			for (int i = 0; i < points.size(); ++i){
				if (points[i].x != cur){
					if (curCount > max){
						max = curCount;
					}
					cur = points[i].x;
					curCount = 0;
				}
				++curCount;
			}
			if (curCount > max){
				max = curCount;
			}
			quickSortForY(points, 0, points.size() - 1);
			curCount = 0;
			for (int i = 0; i < points.size(); ++i){
				if (points[i].y != cur){
					if (curCount > max){
						max = curCount;
					}
					cur = points[i].y;
					curCount = 0;
				}
				++curCount;
			}
			if (curCount > max){
				max = curCount;
			}
			return max;
		}
		else{
			return 0;
		}
	}
	int maxPoints(vector<Point> &points) {
		int maxLine = 0;

		if (points.size() <= 2)
			return points.size();

		for (int i = 0; i<points.size() - 1; i++) {
			int coincident = 0;
			int h = 0;
			map<double, int> pointCounts;
			map<double, int>::iterator it;
			for (int j = i + 1; j<points.size(); j++) {
				double slope;
				if (points[i].x == points[j].x && points[i].y == points[j].y) {
					coincident++;//�����ظ�Ԫ�أ�ֱ����ÿһ�������õ��ֱ���϶���1
					continue;
				}
				else if (points[i].x == points[j].x) {
					h++;//����б�ʲ����ڵ���������⴦��
					continue;
				}
				else if (points[i].y == points[j].y) {
					slope = 0.0; // double���ͷ���0�븺0���ڼ�����ڵı�ʾ��һ��������Ҫ�ڴ��ر����
				}
				else {
					slope = (double)(points[i].y - points[j].y) / (points[i].x - points[j].x);
				}

				it = pointCounts.find(slope);
				if (it != pointCounts.end())
					it->second += 1;
				else
					pointCounts.insert(pair<double, int>(slope, 1));
			}
			coincident++;//������Ϊi��Ԫ�ؼ�������
			h = h + coincident;//�����ظ�Ԫ��
			if (maxLine < h)
				maxLine = h;
			for (it = pointCounts.begin(); it != pointCounts.end(); it++){
				if (maxLine < (it->second + coincident)){
					maxLine = it->second + coincident;
				}
			}
		}
		return maxLine;
	}
};

int main(){
	vector<Point> ps = vector<Point>();
	Point p(0, 0);
	ps.push_back(p);
	ps.push_back(p);
	Solution s;
	cout << s.maxPoints(ps) << endl;
	return 0;
}