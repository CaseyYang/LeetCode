#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result = vector<string>();
		vector<string> tmpResult = vector<string>();
		int curLength = 0;
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
				curLength = 0;
				++i;
				continue;
			}
			if (curLength + 1 + words[i].size() > L){
				int spacePlaceCount = tmpResult.size() - 1;
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
				curLength = 0;
				continue;
			}
		}
		if (tmpResult.size() != 0){
			int spacePlaceCount = tmpResult.size() - 1;
			if (tmpResult.size() == 1){
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
		}
		return result;
	}
};
int main(){
	string rawStrs[] = { "This", "is", "an", "example", "of", "text", "justification." };
	vector<string> strs = vector<string>();
	for (int i = 0; i < 7; ++i){
		strs.push_back(rawStrs[i]);
	}
	Solution s;
	auto result = s.fullJustify(strs, 16);
	for (int i = 0; i < result.size(); ++i){
		cout << result[i] <<"#"<< endl;
	}
	return 0;
}