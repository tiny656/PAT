#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode {
public:
	TreeNode *left, *right;
	int value;

	TreeNode() : left(nullptr), right(nullptr) {}
};

// build tree from in order and pre order
TreeNode* build(const vector<int> &in, const vector<int> &pre, int inLeft, int inRight, int preLeft, int preRight) {
	if (inLeft > inRight) return nullptr;
	int rootValue = pre[preLeft];
	int rootIndex = inLeft;
	while (rootIndex <= inRight && in[rootIndex] != rootValue) rootIndex++;
	int leftSize = rootIndex - inLeft;
	TreeNode* root = new TreeNode();
	root->value = rootValue;
	root->left = build(in, pre, inLeft, rootIndex - 1, preLeft + 1, preLeft + leftSize);
	root->right = build(in, pre, rootIndex + 1, inRight, preLeft + leftSize + 1, preRight);
	return root;
}

// change based level order, only print 1st element in each level
void printLeftView(TreeNode *root) {
	if (root == nullptr) return;
	queue<pair<TreeNode*,int>> q;
	vector<bool> vis(21, false);
	bool isFirstElem = true;
	q.push({root, 1});
	while (!q.empty()) {
		pair<TreeNode*, int> e = q.front();
		q.pop();
		if (!vis[e.second]) {
			vis[e.second] = true;

			if (isFirstElem) {
				cout << e.first->value;
				isFirstElem = false;
			} else cout << " " << e.first->value;
		}
		if (e.first->left != nullptr) q.push({e.first->left, e.second+1});
		if (e.first->right != nullptr) q.push({e.first->right, e.second+1});
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> in(n), pre(n);
	for (int i = 0; i < n; i++) cin >> in[i];
	for (int i = 0; i < n; i++) cin >> pre[i];
	TreeNode *root = build(in, pre, 0, in.size()-1, 0, pre.size()-1);
	printLeftView(root);
	return 0;
}
