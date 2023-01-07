#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
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

void MirrorInverse(TreeNode* node) {
    if (node == NULL || (node->left == NULL && node->right == NULL)) return;

    swap(node->left, node->right);

    MirrorInverse(node->left);
    MirrorInverse(node->right);
}

void PrintLevelOrder(TreeNode* root) {
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* t = q.front();
        ans.push_back(t->data);
        q.pop();
        if (t->left != nullptr) q.push(t->left);
        if (t->right != nullptr) q.push(t->right);
    }

    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> inOrder(n), preOrder(n);
    for (int i = 0; i< n; i++) cin >> inOrder[i];
    for (int i = 0; i< n; i++) cin >> preOrder[i];
    TreeNode* root = BuildTree(inOrder, preOrder, 0, n-1, 0, n-1);
    MirrorInverse(root);
    PrintLevelOrder(root);

    return 0;

}