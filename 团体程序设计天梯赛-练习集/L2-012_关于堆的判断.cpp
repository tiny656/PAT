#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_map>
using namespace std;

#define left(x) (x << 1)
#define right(x) (x << 1 | 1)
#define parent(x) (x >> 1)

void Insert(vector<int> &heap, int val) {
    heap.push_back(val);
    int index = heap.size() - 1;
    int parent = parent(index);
    while (index > 1) {
        if (heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = parent(index);
        } else break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> heap;
    heap.push_back(0);
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        Insert(heap, val);
    }
    
    unordered_map<int, int> pos;
    for (int i = 1; i <= n; i++) pos[heap[i]] = i;

    // for (auto p : heap) cout << p << " ";
    // cout << endl << endl;

    string s;
    getline(cin, s);
    for (int i = 0; i < m; i++) {
        getline(cin, s);
        vector<regex> statements = {
            regex("(-?\\d+) is the root"),
            regex("(-?\\d+) and (-?\\d+) are siblings"),
            regex("(-?\\d+) is the parent of (-?\\d+)"),
            regex("(-?\\d+) is a child of (-?\\d+)")
        };

        for (unsigned int i = 0; i < statements.size(); i++) {
            smatch sm; 
            regex_search(s, sm, statements[i]);
            if (sm.size() > 0) {
                if (i == 0) {
                    int x = atoi(sm[1].str().c_str());
                    int root = heap[1];
                    cout << (x == root ? "T" : "F")<< endl;
                }

                if (i == 1) {
                    // siblings means same level and same parent
                    int x = atoi(sm[1].str().c_str());
                    int y = atoi(sm[2].str().c_str());
                    int parentOfX = heap[parent(pos[x])];
                    int parentOfY = heap[parent(pos[y])];
                    cout << (parentOfX == parentOfY ? "T" : "F")<< endl;
                }

                if (i == 2) {
                    int x = atoi(sm[1].str().c_str());
                    int y = atoi(sm[2].str().c_str());
                    int parentOfY = heap[parent(pos[y])];
                    cout << (x == parentOfY ? "T" : "F") << endl;
                }

                if (i == 3) {
                    int x = atoi(sm[1].str().c_str());
                    int y = atoi(sm[2].str().c_str());
                    int parentOfX = heap[parent(pos[x])];
                    cout << (y == parentOfX ? "T" : "F") << endl;
                }
            }
        }
    }

    return 0;
}