#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class TreeNode {
public:
	TreeNode(int v) :data(v), left(NULL), right(NULL) { }

	int data;
	TreeNode *left;
	TreeNode *right;
};

class BinarySearchTree {
public:
	BinarySearchTree(int n) {
		this->nodeNum = n;
	}

	void build(const vector<int> &preOrd, const vector<int> &inOrd) {
		this->root = this->internalBuild(preOrd, inOrd, 0, preOrd.size() - 1, 0, inOrd.size() - 1);
	}

	bool isIn(int v) {
		return this->valToTreeNode.find(v) != this->valToTreeNode.end();
	}

	int findLCA(int u, int v) {
		TreeNode *t = this->root;
		while (t) {
			if (t->data > v) t = t->left;
			else if (t->data < u) t = t->right;
			else return t->data;
		}
		return -1;
	}

private:
	// build binary tree from pre order and in order
	TreeNode* internalBuild(const vector<int> &preOrd, const vector<int> &inOrd, 
		int preLeft, int preRight, int inLeft, int inRight) {
		TreeNode *node = new TreeNode(preOrd[preLeft]);
		int inRootPos;
		for (inRootPos = inLeft; inRootPos <= inRight; inRootPos++)
			if (inOrd[inRootPos] == node->data) break;
		int leftSize = inRootPos - inLeft;
		int rightSize = inRight - inRootPos;
		if (leftSize > 0)
			node->left = this->internalBuild(preOrd, inOrd, preLeft + 1, preLeft + leftSize, inLeft, inRootPos - 1);
		if (rightSize > 0)
			node->right = this->internalBuild(preOrd, inOrd, preLeft + leftSize + 1, preRight, inRootPos + 1, inRight);
		this->valToTreeNode[node->data] = node;
		return node;
	}

private:
	int nodeNum;
	TreeNode * root;
	unordered_map<int, TreeNode*> valToTreeNode; // map value to tree node pointer
};

int main() {
	int m, n, u, v;
	cin >> m >> n;
	BinarySearchTree bst(n);
	vector<int> preOrd(n), inOrd(n);
	for (int i = 0; i < n; i++) {
		cin >> preOrd[i];
		inOrd[i] = preOrd[i]; // inOrd doesn't mean elements from 1 to n like example, that sucks.
	}
	sort(inOrd.begin(), inOrd.end());
	bst.build(preOrd, inOrd);
	
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		if (!bst.isIn(u) || !bst.isIn(v)) {
			bool t = !bst.isIn(u) && !bst.isIn(v);
			cout << "ERROR: ";
			if (!bst.isIn(u)) cout << u << " ";
			if (t) cout << "and ";
			if (!bst.isIn(v)) cout << v << " ";
			cout << (t ? "are" : "is") << " not found." << endl;
		} else {
			int lca = bst.findLCA(u > v ? v : u, u > v ? u : v);
			if (lca != u && lca != v) {
				cout << "LCA of " << u << " and " << v << " is " << lca << "." << endl;
			} else {
				cout << (lca == u ? u : v) << " is an ancestor of " << (u + v - lca) << "." << endl;
 			}
		}
	}
	return 0;
}