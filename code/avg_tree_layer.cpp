#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
};

class Solution {
public:
	vector<float> averageOfLevels(TreeNode* root) {
		queue<TreeNode *> que;
		que.push(root);
		vector<float> avg;
		while (!que.empty())
		{
			int size = que.size();
			float sum = 0;
			for (int i = 0; i < size; i++)
			{
				sum += que.front()->val;
				if (que.front()->left != NULL) {
					que.push(que.front()->left);
				}
				if (que.front()->right != NULL) {
					que.push(que.front()->right);
				}
				que.pop();
			}
			avg.push_back(sum / size);
		}
		return avg;
	}
};

void print(vector<float> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	TreeNode root_right_left = { 3 , 0, 0 };
	TreeNode root_right = { 2, &root_right_left, 0 };
	TreeNode root = { 1, 0, &root_right };

	Solution s;
	print(s.averageOfLevels(&root));

	system("pause");
	return 0;
}