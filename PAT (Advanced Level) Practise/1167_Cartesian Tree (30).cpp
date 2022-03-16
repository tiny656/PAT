#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

vector<int> leftMin, rightMin;

Node* Build(int lo, int hi, const vector<int> &in) {
    // maintain the minimum array (left -> right) as leftMin
    // maintain the minimum array (right -> left) as rightMin
    for (int i = lo; i <= hi; i++) {
        leftMin[i] = i == lo ? in[lo] : min(leftMin[i-1], in[i]);
        rightMin[hi+lo-i] = i == lo ? in[hi] : min(rightMin[hi+lo-i+1], in[hi+lo-i]);
    }

    int pos;
    for (int i = lo; i <= hi; i++) {
        // root pos in inroder array of cartesian tree meets the below condition
        // leftMin[pos-1] > a[pos] < rightMin[pos+1], so root node is on the pos. 
        if ((i <= lo || in[i] < leftMin[i-1]) && (i >= hi || in[i] < rightMin[i+1])) {
            pos = i;
            break;
        }
    }

    Node* node = new Node(in[pos]);

    int leftCount = pos - lo;
    int rightCount = hi - pos;
    if (leftCount > 0) node->left = Build(lo, pos-1, in);
    if (rightCount > 0) node->right = Build(pos+1, hi, in);

    return node;
}

void PrintLevelOrder(Node* root) {
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* t = q.front();
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

    vector<int> in(n);
    leftMin.resize(n);
    rightMin.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    Node* root = Build(0, in.size()-1, in);
    PrintLevelOrder(root);

    return 0;
}