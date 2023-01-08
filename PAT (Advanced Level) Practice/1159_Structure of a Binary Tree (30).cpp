#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;

struct Node {
    int parent;
    int left;
    int right;
    int data;
    int level;
};

unordered_map<int, Node> nodes;

// inOrder and postOrder to build a tree
int Build(int level, int parent, const vector<int> &in, int inLeft, int inRight, 
    const vector<int> &post, int postLeft, int postRight, bool &isFullTree) {

    int pos;
    int root = post[postRight];
    for (pos = inLeft; pos <= inRight && in[pos] != root; pos++); 

    Node node;
    node.data = root;
    node.parent = parent;
    node.left = node.right = -1;
    node.level = level;

    int leftCount = pos - inLeft;
    int rightCount = inRight - pos;

    if (leftCount > 0)
        node.left = Build(level + 1, root, in, inLeft, pos - 1, post, postLeft, postLeft + leftCount - 1, isFullTree);
    if (rightCount > 0)
        node.right = Build(level+1, root, in, pos + 1, inRight, post, postLeft + leftCount, postRight - 1, isFullTree);

    if ((node.left == -1 && node.right != -1) || (node.left != -1 && node.right == -1)) isFullTree = false;

    nodes[node.data] = node;
    return node.data;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n;
    vector<int> in(n), post(n);
    for (int i = 0; i < n; i++)  cin >> post[i];
    for (int i = 0; i < n; i++)  cin >> in[i];

    bool isFullTree = true;
    Build(0, -1, in, 0, in.size()-1, post, 0, post.size()-1, isFullTree);

    string s;
    cin >> m;
    getline(cin, s);
    for (int i = 0; i < m; i++) {
        getline(cin, s);
        vector<regex> statements = {
            regex("(\\d+) is the root"),
            regex("(\\d+) and (\\d+) are siblings"),
            regex("(\\d+) is the parent of (\\d+)"),
            regex("(\\d+) is the left child of (\\d+)"),
            regex("(\\d+) is the right child of (\\d+)"),
            regex("(\\d+) and (\\d+) are on the same level"),
            regex("It is a full tree")
        };

        for (int i = 0; i < statements.size(); i++) {
            smatch sm; 
            regex_search(s, sm, statements[i]);
            if (sm.size() > 0) {
                if (i == 0) cout << (nodes[atoi(sm[1].str().c_str())].parent == -1 ? "Yes" : "No") << endl;
                if (i == 1) {
                    // siblings means same level and same parent
                    Node a = nodes[atoi(sm[1].str().c_str())];
                    Node b = nodes[atoi(sm[2].str().c_str())];
                    cout << (a.level == b.level && a.parent == b.parent ? "Yes" : "No") << endl;
                }
                if (i == 2) cout << (atoi(sm[1].str().c_str()) == nodes[atoi(sm[2].str().c_str())].parent ? "Yes" : "No") << endl;
                if (i == 3) cout << (atoi(sm[1].str().c_str()) == nodes[atoi(sm[2].str().c_str())].left ? "Yes" : "No") << endl;
                if (i == 4) cout << (atoi(sm[1].str().c_str()) == nodes[atoi(sm[2].str().c_str())].right ? "Yes" : "No") << endl;
                if (i == 5) cout << (nodes[atoi(sm[1].str().c_str())].level == nodes[atoi(sm[2].str().c_str())].level ? "Yes" : "No") << endl;
                if (i == 6) cout << (isFullTree ? "Yes" : "No") << endl;
            }
        }
    }

    return 0;
}