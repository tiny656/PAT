#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int k1, k2;
    int left, right;
    Node() { }
    Node(int k1, int k2, int left, int right):k1(k1), k2(k2), left(left), right(right) { }

};

bool IsBST(int root, const vector<Node> &nodeList) {
    if (root == -1) return true;
    Node node = nodeList[root];
    if (node.left == -1 && node.right == -1)  return true;

    // if right node is not empty
    if (node.right != -1) {
        Node tmp = nodeList[node.right];
        // find the most left node
        while (tmp.left != -1) tmp = nodeList[tmp.left];
        if (tmp.k1 <= node.k1) return false;
    } 

    // if left node is not empty
    if (node.left != -1) {
        Node tmp = nodeList[node.left];
        // find the most right node
        while (tmp.right != -1) tmp = nodeList[tmp.right];
        if (tmp.k1 >= node.k1) return false;
    } 

    return IsBST(node.left, nodeList) && IsBST(node.right, nodeList);
}

int GetMin(int root, const vector<Node> &nodeList) {
    if (root == -1) return 0x7fffffff;
    Node node = nodeList[root];
    if (node.left == -1 && node.right == -1) return node.k2;
    int minLeft = GetMin(node.left, nodeList);
    int minRight = GetMin(node.right, nodeList);
    return minLeft < minRight ? minLeft : minRight;
}

bool IsSmallHeap(int root, const vector<Node> &nodeList) {
    if (root == -1) return true;
    Node node = nodeList[root];
    if (node.left == -1 && node.right == -1) return true;
    int leftVal = 0x7fffffff, rightVal = 0x7fffffff;
    if (node.left != -1) leftVal = nodeList[node.left].k2;
    if (node.right != -1) rightVal = nodeList[node.right].k2;
    if (node.k2 >= leftVal || node.k2 >= rightVal) return false;
    return IsSmallHeap(node.left, nodeList) && IsSmallHeap(node.right, nodeList);
}

int main() {
    int n, k1, k2, left, right;
    cin >> n;
    vector<Node> nodeList(n);
    vector<int> inCount(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> k1 >> k2 >> left >> right;
        nodeList[i] = Node(k1, k2, left, right);
        if (left != -1) inCount[left]++;
        if (right != -1) inCount[right]++;
    }

    int root = -1;
    for (int i = 0; i < n && root == -1; i++) {
        if (inCount[i] == 0) root = i;
    }

    bool ok = IsBST(root, nodeList) && IsSmallHeap(root, nodeList);
    cout << (ok ? "YES" : "NO") << endl;

    return 0;
}