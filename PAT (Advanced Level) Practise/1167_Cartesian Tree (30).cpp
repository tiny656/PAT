#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    int left;
    int right;
    int data;
};

vector<int> leftMin, rightMin;
unordered_map<int, Node> nodes;

int Build(int lo, int hi, const vector<int> &in) {
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


    Node node;
    node.left = node.right = -1;

    int leftCount = pos - lo;
    int rightCount = hi - pos;
    if (leftCount > 0) node.left = Build(lo, pos-1, in);
    if (rightCount > 0) node.right = Build(pos+1, hi, in);

    node.data = in[pos];
    nodes[node.data] = node;

    return node.data;
}

void PrintLevelOrder(int root) {
    vector<int> ans;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        Node t = nodes[q.front()];
        ans.push_back(t.data);
        q.pop();
        if (t.left != -1) q.push(t.left);
        if (t.right != -1) q.push(t.right);
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

    int root = Build(0, in.size()-1, in);

    PrintLevelOrder(root);

    return 0;
}