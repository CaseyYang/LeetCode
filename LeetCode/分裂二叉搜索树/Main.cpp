#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
};

//�㷨˼·��
//�Ͷ��������������½�����ƣ��ӴӸ���㿪ʼѰ�Ҳ���λ�á�
//�����ǰ���ȷָ�ֵ����ǰ������ڱȷָ�ֵ����ǿ���������biggerRootΪ�������������ѵ�ǰ�������ǿ�������һ���ڵ㣨��biggerTreeCur��¼����������
//�����ǰ���ȷָ�ֵС����ǰ������ڱȷָ�ֵС���ǿ���������smallerRootΪ�������������ѵ�ǰ�������ǿ�������һ���ڵ㣨��smallerTreeCur��¼����������
//������̿���ʹ�ôӸ���㿪ʼ�Ķ���������ģ�⣬���ɸ�֪Ϊ��һ���ǲ���biggerTreeCur�����/smallerTreeCur���Ҳ�
vector<TreeNode*> func(TreeNode* root, int n) {
	TreeNode* biggerRoot = NULL;
	TreeNode* biggerTreeCur = NULL;
	TreeNode* smallerRoot = NULL;
	TreeNode* smallerTreeCur = NULL;
	TreeNode* cur = root;
	while (cur != NULL) {
		if (n < cur->value) {
			if (biggerRoot == NULL) {
				biggerRoot = cur;
				biggerTreeCur = cur;
			}
			else {
				biggerTreeCur->left = cur;
				biggerTreeCur = biggerTreeCur->left;
			}
			cur = cur->left;
		}
		else {
			if (smallerRoot == NULL) {
				smallerRoot = cur;
				smallerTreeCur = cur;
			}
			else {
				smallerTreeCur->right = cur;
				smallerTreeCur = smallerTreeCur->right;
			}
			cur = cur->right;
		}
	}
	vector<TreeNode*> result = vector<TreeNode*>();
	result.push_back(biggerRoot);
	result.push_back(smallerRoot);
	return result;
}

int main() {
	return 0;
}