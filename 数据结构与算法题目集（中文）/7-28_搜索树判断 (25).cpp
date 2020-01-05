#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node *left, *right;
    int val;
};

Node* BuildTree(Node* root, int x) {
    if (root == NULL) {
        root = new Node();
        root->left = root->right = NULL;
        root->val = x;
    } else if (x >= root->val) root->right = BuildTree(root->right, x);
    else root->left = BuildTree(root->left, x);
    return root;
}

void GetPreOrder(Node *root, bool isMirror, vector<int> &result) {
    if (root != NULL) {
        result.push_back(root->val);
        if (!isMirror) {
            GetPreOrder(root->left, isMirror, result);
            GetPreOrder(root->right, isMirror, result);
        } else {
            GetPreOrder(root->right, isMirror, result);
            GetPreOrder(root->left, isMirror, result);
        }
    }
}

bool IsSameVector(const vector<int> &a, const vector<int> &b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void PrintPostOrder(Node* root, bool &isFirstItem, bool isMirror) {
    if (root != NULL) {
        if (!isMirror) {
            PrintPostOrder(root->left, isFirstItem, isMirror);
            PrintPostOrder(root->right, isFirstItem, isMirror);
        } else {
            PrintPostOrder(root->right, isFirstItem, isMirror);
            PrintPostOrder(root->left, isFirstItem, isMirror);
        }
        if (isFirstItem) {
            cout << root->val;
            isFirstItem = false;
        } else cout << " " << root->val;
    }
}

int main() {
    bool isFirstItem = true;
    int n;
    cin >> n;
    vector<int> preOrder(n);
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> preOrder[i];
        root = BuildTree(root, preOrder[i]); // follow BST rules to build tree
    }
    vector<int> calcPreOrder1, calcPreOrder2;
    GetPreOrder(root, false, calcPreOrder1); // calc non mirror pre order
    GetPreOrder(root, true, calcPreOrder2); // calc mirror pre order
    if (IsSameVector(preOrder, calcPreOrder1)) {
        cout << "YES" << endl;
        PrintPostOrder(root, isFirstItem, false);
    } else if (IsSameVector(preOrder, calcPreOrder2)) {
        cout << "YES" << endl;
        PrintPostOrder(root, isFirstItem, true);
    } else cout << "NO" << endl;

    return 0;
}