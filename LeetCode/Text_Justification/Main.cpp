#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result = vector<string>();
		vector<string> tmpResult = vector<string>();
		int curLength = -1;
		for (int i = 0; i < words.size();){
			if (curLength + 1 + words[i].size() < L){
				tmpResult.push_back(words[i]);
				curLength += 1 + words[i].size();
				++i;
				continue;
			}
			if (curLength + 1 + words[i].size() == L){
				tmpResult.push_back(words[i]);
				string tmpStr = "";
				for (int j = 0; j < tmpResult.size(); ++j){
					tmpStr.append(tmpResult[j]);
					if (j < tmpResult.size() - 1) tmpStr.append(" ");
				}
				result.push_back(tmpStr);
				tmpResult.clear();
				curLength = -1;
				++i;
				continue;
			}
			if (curLength + 1 + words[i].size() > L){
				int spacePlaceCount = tmpResult.size() - 1;
				if (spacePlaceCount < 0){

				}
				if (spacePlaceCount == 0){
					string tmpStr = "";
					int spaceCount = L - curLength;
					tmpStr.append(tmpResult[0]);
					for (int j = 0; j < spaceCount; ++j) tmpStr.append(" ");
					result.push_back(tmpStr);
				}
				else{
					int averageSpace = (L - curLength) / spacePlaceCount;
					int remainder = (L - curLength) % spacePlaceCount;
					string tmpStr = "";
					for (int j = 0; j < tmpResult.size(); ++j){
						tmpStr.append(tmpResult[j]);
						if (j < tmpResult.size() - 1){
							tmpStr.append(" ");
							for (int k = 0; k < averageSpace; ++k){
								tmpStr.append(" ");
							}
							if (remainder > 0){
								tmpStr.append(" ");
								--remainder;
							}
						}
					}
					result.push_back(tmpStr);
				}
				tmpResult.clear();
				curLength = -1;
				continue;
			}
		}
		if (tmpResult.size() > 0){
			string tmpStr = "";
			for (int i = 0; i < tmpResult.size(); ++i){
				tmpStr.append(tmpResult[i]);
				if (i < tmpResult.size() - 1) tmpStr.append(" ");
			}
			int length = tmpStr.size();
			for (int i = 0; i < L - length; ++i){
				tmpStr.append(" ");
			}
			result.push_back(tmpStr);
		}
		return result;
	}
};
int main(){
	//string rawStrs[] = { "This", "is", "an", "example", "of", "text", "justification." };
	string rawStrs[] = { "What", "must", "be", "shall", "be." };
	vector<string> strs = vector<string>();
	for (int i = 0; i < 5; ++i){
		strs.push_back(rawStrs[i]);
	}
	Solution s;
	auto result = s.fullJustify(strs, 12);
	for (int i = 0; i < result.size(); ++i){
		cout << result[i] << "#" << endl;
	}
	return 0;
}