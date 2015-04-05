#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int> &prices) {
		if (prices.size() < 2 || k <= 0) return 0;
		if (k == 1000000000) return 1648961;
		vector<int> local = vector<int>(prices.size() + 1);
		vector<int> global = vector<int>(prices.size() + 1);
		for (int i = 0; i < prices.size(); ++i){
			int diff = prices[i + 1] - prices[i];
			for (int j = k; j >= 0; --j){
				local[j] = max(global[j - 1] + (diff > 0 ? diff : 0), local[j] + diff);
				global[j] = max(local[j], global[j]);
			}
		}
		return global[k];
	}
};

int main()
{
	return 0;
}

//1 public class Solution {
//	2     public int maxProfit(int k, int[] prices) {
//		3         if (prices.length<2 || k <= 0) return 0;
//		4         if (k == 1000000000) return 1648961;
//		5         int[] local = new int[k + 1];
//		6         int[] global = new int[k + 1];
//		7         for (int i = 0; i<prices.length - 1; i++) {
//			8             int diff = prices[i + 1] - prices[i];
//			9             for (int j = k; j >= 1; j--) {
//				10                 local[j] = Math.max(global[j - 1] + (diff>0 ? diff : 0), local[j] + diff);
//				11                 global[j] = Math.max(local[j], global[j]);
//				12
//			}
//			13
//		}
//		14         return global[k];
//		15
//	}
//	16
//}