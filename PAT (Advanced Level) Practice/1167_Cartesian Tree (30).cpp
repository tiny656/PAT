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

Node* Build(int lo, int hi, const vector<int> &in) {
    // root pos in inroder array of cartesian tree meets the below condition
    // in[pos] is the minimal element in the range(lo, hi), so root node is on the pos. 

    // TODO: RMQ can be optimized with Sparse Table
    int val = in[lo], pos = lo;
    for (int i = lo+1; i <= hi; i++) {
        if (in[i] < val) {
            pos = i;
            val = in[i];
        }
    }

    Node* node = new Node(val);

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

    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    Node* root = Build(0, in.size()-1, in);
    PrintLevelOrder(root);

    return 0;
}
