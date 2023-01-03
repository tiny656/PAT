#include <iostream>
#include <vector>
using namespace std;

class Tree {
public:
    int val[1005];
    int numOfNode;

    Tree():minCompare(true), maxCompare(true) { }

    void Search(int root) {
        curPath.push_back(this->val[root]);
        if (this->hasRight(root)) this->Search(this->rightIdx(root));
        if (this->hasLeft(root)) this->Search(this->leftIdx(root));
        if (!this->hasRight(root) && !this->hasLeft(root)) {
            path.push_back(vector<int>(curPath.begin(), curPath.end()));
            for (int i = 0; i < curPath.size()-1; i++) {
                this->minCompare &= curPath[i] <= curPath[i+1];
                this->maxCompare &= curPath[i] >= curPath[i+1];
            }
        }
        curPath.pop_back();
    }

    void PrintAnswer() {
        for (int i = 0; i < this->path.size(); i++) {
            bool first = true;
            for (const auto &v : this->path[i]) {
                if (first) {
                    cout << v;
                    first = false;
                } else {
                    cout << " " << v;
                }
            }
            cout << endl;
        }
        if (this->minCompare) cout << "Min Heap" << endl;
        else if (this->maxCompare) cout << "Max Heap" << endl;
        else cout << "Not Heap" << endl;
    }

private:
    vector<vector<int>> path;
    vector<int> curPath;
    bool minCompare, maxCompare;

    bool hasLeft(int root) { return (root << 1) <= numOfNode; }
    bool hasRight(int root) { return (root << 1) + 1 <= numOfNode; }
    int leftIdx(int root) { return root << 1; }
    int rightIdx(int root) { return (root << 1) + 1; }

};

int main() {
    int n;
    Tree tree = Tree();
    cin >> n;
    tree.numOfNode = n;
    for (int i = 1; i <= n; i++) {
        cin >> tree.val[i];
    }
    tree.Search(1);
    tree.PrintAnswer();
    return 0;
}