#include<iostream>
using namespace std;
class Solution {
public:
	int strStr(char *haystack, char *needle)
	{
		const int n = strlen(haystack), m = strlen(needle);
		if (!m)
			return 0;
		int next[m], i, j;
		next[i = 0] = j = -1;
		//求取next数组
		while (i < m - 1)
		{
			if (j == -1 || needle[i] == needle[j])
				next[++i] = ++j;
			else
				j = next[j];
		}
		//模式匹配
		for (i = j = 0; i < n;)
		{
			if (j == -1 || haystack[i] == needle[j])
				++i, ++j;
			else
				j = next[j];
			if (j == m)
				return i - m;
		}
		return -1;
	}

};
int main(){
	return 0;
}