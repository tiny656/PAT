#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <vector>
using namespace std;

struct Node {
    int address;
    int data;
    int next;
};

unordered_map<int, Node> Nodes;

int Reverse(int head) {
    int prev = -1, cur = head;
    while (cur != -1) {
        int next = Nodes[cur].next;
        Nodes[cur].next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int GetSize(int addr) {
    int count = 0;
    for (int p = addr; p != -1; p = Nodes[p].next) count++;
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    int L1_root, L2_root;
    int n;
    cin >> L1_root >> L2_root >> n;
    for (int i = 0; i < n; i++) {
        Node node;
        cin >> node.address >> node.data >> node.next;
        Nodes[node.address] = node;
    }

    if (GetSize(L1_root) < GetSize(L2_root)) swap(L1_root, L2_root);
    L2_root = Reverse(L2_root);

    int count = 0;
    vector<Node> res;
    int p = L1_root, q = L2_root;
    while (p != -1) {
        count++;
        res.push_back(Nodes[p]);
        p = Nodes[p].next;
        if (count % 2 == 0 && q != -1) {
            res.push_back(Nodes[q]);
            q = Nodes[q].next;
        }
    }

    for (int i = 0; i < res.size(); i++) {
        cout << setfill('0') << setw(5) << res[i].address << " " << res[i].data << " ";
        if (i == res.size()-1) cout << "-1" << endl;
        else cout << setfill('0') << setw(5) << res[i+1].address << endl;
    }

    return 0;
}