#include <bits/stdc++.h>
using namespace std;

// invert binary tree
void inverseTree(vector<int> treeNode[], int root) {
    swap(treeNode[root][0], treeNode[root][1]);
    if (treeNode[root][0] != -1) inverseTree(treeNode, treeNode[root][0]);
    if (treeNode[root][1] != -1) inverseTree(treeNode, treeNode[root][1]);
}

// compute level order of binary tree
void levelOrder(const vector<int> treeNode[], int root, vector<int> &ret) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        ret.push_back(node);
        if (treeNode[node][0] != -1) q.push(treeNode[node][0]);
        if (treeNode[node][1] != -1) q.push(treeNode[node][1]);
    }
}

// compute inorder of binary tree
void inOrder(const vector<int> treeNode[], int root, vector<int> &ret) {
    if (root == -1) return;
    inOrder(treeNode, treeNode[root][0], ret);
    ret.push_back(root);
    inOrder(treeNode, treeNode[root][1], ret);
}

// print the answer
void printAnswer(const vector<int> &result) {
    if (!result.empty()) {
        printf("%d", result[0]);
        for (int i = 1; i < result.size(); i++) printf(" %d", result[i]);
    }
    printf("\n");
}

int main() {
    int n;
    char a, b;
    scanf("%d", &n);
    vector<int> treeNode[10]; // tree structure, it seems like adjacent table
    int root = n*(n-1)/2; // math method to compute root
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c %c", &a, &b);
        treeNode[i].push_back(a=='-' ? -1 : (root-=a-'0',a-'0'));
        treeNode[i].push_back(b=='-' ? -1 : (root-=b-'0',b-'0'));
    }
    inverseTree(treeNode, root);
    vector<int> levelOrderResult, inOrderResult;
    levelOrder(treeNode, root, levelOrderResult);
    inOrder(treeNode, root, inOrderResult);
    printAnswer(levelOrderResult);
    printAnswer(inOrderResult);
    return 0;
}