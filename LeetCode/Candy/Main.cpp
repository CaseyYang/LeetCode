#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//int candy(vector<int> &ratings) {
	//	int Total = 0;    /// Total candies
	//	int length = 0;  /// Continuous descending length of rate
	//	int nPreCanCnt = 1; /// Previous child's candy count
	//	int beforeDenc = nPreCanCnt;
	//	if (ratings.size() > 0)
	//	{
	//		Total++; //Counting the first child's candy (1).
	//		for (int i = 0; i < ratings.size(); ++i)
	//		{
	//			if (ratings[i - 1] > ratings[i])
	//			{
	//				++length;
	//				if (beforeDenc <= length)
	//				{
	//					Total++;//波峰的糖果数+1
	//				}
	//				Total += length;//所有递减区段的糖果数+1
	//				nPreCanCnt = 1;//当前波谷的糖果数总是1
	//			}
	//			else
	//			{
	//				int curCanCnt = 0;
	//				if (ratings[i] > ratings[i - 1])
	//				{
	//					curCanCnt = (nPreCanCnt + 1);
	//				}
	//				else
	//				{
	//					curCanCnt = 1;//如果相邻两个孩子的rating一样，则第二个的糖果只有1
	//				}
	//				Total += curCanCnt;
	//				nPreCanCnt = curCanCnt;
	//				length = 0;    //reset length of decending sequence
	//				beforeDenc = curCanCnt;
	//			}
	//		}
	//	}
	//	return Total;
	//}
	int candy(vector<int> &ratings) {
		if (ratings.size() == 0 || ratings.size() == 1){
			return ratings.size();
		}
		else{
			int preMax = 0;
			int decendingLength = 0;
			int totalCandys = 1;
			int curCandy = 1;
			for (int i = 1; i < ratings.size(); ++i){
				if (ratings[i - 1] <= ratings[i]){
					if (ratings[i - 1] == ratings[i]){
						curCandy = 1;
					}
					else{
						++curCandy;
					}
					preMax = curCandy;
					totalCandys += curCandy;
					decendingLength = 0;
					continue;
				}
				else{
					++decendingLength;
					if (preMax <= decendingLength){
						++totalCandys;
					}					
					totalCandys += decendingLength;
					curCandy = 1;
				}
			}
			return totalCandys;
		}
	}
};

int main(){
	int a[5] = { 4,2,3,4,1};
	vector<int> r = vector<int>(a, a + 5);
	Solution s;
	cout << s.candy(r) << endl;
	return 0;
}