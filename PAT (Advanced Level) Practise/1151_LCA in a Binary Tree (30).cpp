#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class TreeNode {
public:
    TreeNode *left, *right;
    int data;
    TreeNode(int data):data(data), left(NULL), right(NULL) {}
};

unordered_map<int, TreeNode*> treeMap;

TreeNode* BuildTree(
    const vector<int> &in, 
    const vector<int> &pre, 
    int inLeft, 
    int inRight, 
    int preLeft, 
    int preRight) {
    int root = pre[preLeft], pos;
    for (pos = inLeft; pos <= inRight; pos++) {
        if (in[pos] == root) break;
    }
    int leftSize = pos - inLeft;
    int rightSize = inRight - pos;
    TreeNode *node = new TreeNode(root);
    treeMap[root] = node;
    if (leftSize > 0) node->left = BuildTree(in, pre, inLeft, pos - 1, preLeft + 1, preLeft + pos - inLeft);
    if (rightSize > 0) node->right = BuildTree(in, pre, pos + 1, inRight, preLeft + pos - inLeft + 1, preRight);
    return node;
}

TreeNode* FindLowestCommonAncestor(TreeNode*root, TreeNode* u, TreeNode *v) {
    if (root == NULL || u == root || v == root) return root;
    TreeNode* left = FindLowestCommonAncestor(root->left, u, v);
    TreeNode* right = FindLowestCommonAncestor(root->right, u, v);
    if (left && right) return root;
    else return left ? left : right;
}

int main() {
    int m, n, u, v;
    cin >> m >> n;
    vector<int> inOrder(n), preOrder(n);
    for (int i = 0; i< n; i++)
        cin >> inOrder[i];
    for (int i = 0; i< n; i++)
        cin >> preOrder[i];
    TreeNode *root = BuildTree(inOrder, preOrder, 0, inOrder.size()-1, 0, preOrder.size()-1);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        bool findU = treeMap.find(u) != treeMap.end();
        bool findV = treeMap.find(v) != treeMap.end();
        if (!findU && !findV) {
            cout << "ERROR: " << u << " and " << v << " are not found." << endl;
        } else if (!findU) {
            cout << "ERROR: " << u << " is not found." << endl;
        } else if (!findV) {
            cout << "ERROR: " << v << " is not found." << endl;
        } else {
            TreeNode* ans = FindLowestCommonAncestor(root, treeMap[u], treeMap[v]);
            if (ans->data == u) {
                cout << u << " is an ancestor of " << v << "." << endl;
            } else if (ans->data == v) {
                cout << v << " is an ancestor of " << u << "." << endl;
            } else {
                cout << "LCA of " << u << " and " << v << " is " << ans->data << "." << endl;
            }
        }
    }
    return 0;
}