#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <vector>
using namespace std;

struct Node {
    int address;
    int prev;
    int data;
    int next;
};

unordered_map<int, Node> Nodes;

int GetSize(int addr) {
    int count = 0;
    for (int p = addr; p != -1; p = Nodes[p].next) count++;
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    int L1_root, L2_root, p, q;
    int n;
    cin >> L1_root >> L2_root >> n;
    for (int i = 0; i < n; i++) {
        Node node;
        cin >> node.address >> node.data >> node.next;
        Nodes[node.address] = node;
    }

    if (GetSize(L1_root) < GetSize(L2_root)) swap(L1_root, L2_root);
    
    p = L2_root;
    int L2_prev = -1;
    while (p != -1) {
        Nodes[p].prev = L2_prev;
        L2_prev = p;
        p = Nodes[p].next;
    }

    int count = 0;
    vector<Node> res;
    p = L1_root, q = L2_prev;
    while (p != -1) {
        count++;
        res.push_back(Nodes[p]);
        p = Nodes[p].next;
        if (count % 2 == 0 && q != -1) {
            res.push_back(Nodes[q]);
            q = Nodes[q].prev;
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << setfill('0') << setw(5) << res[i].address << " " << res[i].data << " ";
        if (i == res.size()-1) cout << "-1" << endl;
        else cout << setfill('0') << setw(5) << res[i+1].address << endl;
    }

    return 0;
}