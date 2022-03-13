#include <iostream>
#include <vector>
using namespace std;

struct Node {
    string data;
    int left;
    int right;
};

vector<Node> Tree;

void PrintPostFixExpression(Node root) {
    cout << "(";

    // special prefix case for '-', '+' symbol, and when it only has right child
    bool isOk = false;
    if ((root.data == "-" || root.data == "+") && root.left == -1 && root.right != -1) {
        isOk = true;
        cout << root.data;
    } 

    if (root.left != -1) PrintPostFixExpression(Tree[root.left]);
    if (root.right != -1) PrintPostFixExpression(Tree[root.right]);

    if (!isOk) cout << root.data;
    cout << ")";
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    Tree.resize(n+1);
    vector<bool> vis(n+1, false);
    for (int i = 1; i <= n; i++) {
        Node node;
        cin >> node.data >> node.left >> node.right;
        if (node.left != -1) vis[node.left] = true;
        if (node.right != -1) vis[node.right] = true;
        Tree[i] = node;
    }

    int root;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }

    PrintPostFixExpression(Tree[root]);
    cout << endl;
    return 0;
}

