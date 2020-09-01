#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int data;
	struct TreeNode * left;
	struct TreeNode * right;
};

//递归遍历
void traversal_recursion(TreeNode *root, vector<int> &res) {
	if (root != NULL) {
		if (root->left != NULL) {
			traversal_recursion(root->left, res);
		}
		res.push_back(root->data);
		if (root->right != NULL) {
			traversal_recursion(root->right, res);
		}
	}
}

//基于栈的遍历
void traversal_stack(TreeNode *root, vector<int> &res)
{
	stack<TreeNode*> stk;
	TreeNode * curr = root;
	while (curr != NULL || stk.size()!=0) {
		while (curr != NULL) {
			stk.push(curr);
			curr = curr->left;
		}
		if (stk.size() != 0)
		{
			curr = stk.top();
			stk.pop();
			res.push_back(curr->data);
			curr = curr->right;
		}

	}

}

void print(vector<int> res) {
	cout << res[0];
	if (res.size() == 1) {
		cout << endl;
		return;
	}
	for (int i = 1; i < (int)res.size(); i++) {
		cout << ", ";
		cout << res[i];
	}
	cout << endl;
}

int main()
{
	TreeNode root_right_left = { 3 , 0, 0 };
	TreeNode root_right = { 2, &root_right_left, 0 };
	TreeNode root = { 1, 0, &root_right };
	
	vector<int> res;
	vector<int> res2;

	traversal_recursion(&root, res);
	traversal_stack(&root, res2);

	print(res);
	print(res2);

	system("pause");
	return 0;
}