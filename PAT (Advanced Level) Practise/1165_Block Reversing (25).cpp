#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    string address;
    string data;
    string next;
};

unordered_map<string, Node> L;

int main() {
    ios::sync_with_stdio(false);
    string root;
    int n, k;
    cin >> root >> n >> k;
    for (int i = 0; i < n; i++) {
        Node node;
        cin >> node.address >> node.data >> node.next;
        L[node.address] = node;
    }

    vector<pair<string, string>> blocks; // record every blocks, then reverse based on this
    int count = 0;
    string p = root, begin = root, last;
    while (p != "-1") {
        count++;
        if (count == k) {
            blocks.push_back(make_pair(begin, p));
            begin = L[p].next;
            count = 0;
        }

        last = p;
        p = L[p].next;
    }

    if (begin != "-1") blocks.push_back(make_pair(begin, last));
    for (int i = blocks.size() - 1; i > 0; i--) {
        L[blocks[i].second].next = blocks[i-1].first;
    }
    L[blocks[0].second].next = "-1";

    p = blocks[blocks.size() - 1].first;
    while (p != "-1"){
        cout << p << " " << L[p].data << " " << L[p].next << endl;
        p = L[p].next;
    }

    return 0;
}