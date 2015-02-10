#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int majorityElement(vector<int> &num) {
		int canadidate;
		int count = 0;
		for (int i = 0; i < num.size(); ++i){
			if (count == 0){
				canadidate = num[i];
				++count;
			}
			else{
				if (canadidate == num[i]) ++count;
				else --count;
			}
		}
		return canadidate;
	}
};
int main(){

	return 0;
}