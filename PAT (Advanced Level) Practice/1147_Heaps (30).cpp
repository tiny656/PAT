#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
	TreeNode(int v):data(v), left(NULL), right(NULL) { }

	int data;
	TreeNode *left, *right;
};

class BinaryTree {
public:
	BinaryTree(int n) {
		this->nodeNum = n;
	}

	void build(const vector<int> &levelOrd) {
		root = this->internalBuild(levelOrd, 1);
	}

	bool isMaxHeap() {
		return this->internalIsMaxHeap(this->root);
	}

	bool isMinHeap() {
		return this->internalIsMinHeap(this->root);
	}

	vector<int> getPostOrder() {
		vector<int> postOrd;
		this->internalPostOrder(this->root, postOrd);
		return postOrd;
	}

private:
	// heap must be complete binary tree
	// for node index i, left node index is 2*i, right node index is 2*i+1 
	TreeNode * internalBuild(const vector<int> &levelOrd, int pos) {
		TreeNode *node = new TreeNode(levelOrd[pos]);
		if ((pos << 1) < levelOrd.size())
			node->left = internalBuild(levelOrd, pos << 1);
		if ((pos << 1) + 1 < levelOrd.size())
			node->right = internalBuild(levelOrd, (pos << 1) + 1);
		return node;
	}

	// recursive check max heap definition
	bool internalIsMaxHeap(const TreeNode *node) {
		return (!node->left || node->data >= node->left->data)
			&& (!node->right || node->data >= node->right->data)
			&& (!node->left || this->internalIsMaxHeap(node->left)) 
			&& (!node->right || this->internalIsMaxHeap(node->right));
	}

	// recursive check max heap definition, similar with max heap
	bool internalIsMinHeap(const TreeNode *node) {
		return (!node->left || node->data <= node->left->data)
			&& (!node->right || node->data <= node->right->data)
			&& (!node->left || this->internalIsMinHeap(node->left)) 
			&& (!node->right || this->internalIsMinHeap(node->right));
	}

	void internalPostOrder(TreeNode *node, vector<int> &postOrd) {
		if (!node) return;
		if (node->left) this->internalPostOrder(node->left, postOrd);
		if (node->right) this->internalPostOrder(node->right, postOrd);
		postOrd.push_back(node->data);
	}

	int nodeNum;
	TreeNode *root;
};

int main() {
	int m, n;
	cin >> m >> n;
	vector<int> levelOrd(n + 1);
	BinaryTree bt(n);
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> levelOrd[j];
		}
		bt.build(levelOrd);
		if (bt.isMaxHeap()) cout << "Max Heap" << endl;
		else if (bt.isMinHeap()) cout << "Min Heap" << endl;
		else cout << "Not Heap" << endl;
		vector<int> postOrd = bt.getPostOrder();
		cout << postOrd[0];
		for (int j = 1; j < postOrd.size(); j++)
			cout << " " << postOrd[j];
		cout << endl;
	}

	return 0;
}