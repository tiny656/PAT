#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool IsConnected(const vector<vector<int>> G) {
    vector<bool> isVis(G.size(), false);
    queue<int> q;
    q.push(1);
    isVis[0] = isVis[1] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (const auto &adj : G[cur]) {
            if(!isVis[adj]) {
                isVis[adj] = true;
                q.push(adj);
            }
        }
    }

    for (const auto &vis : isVis) {
        if (!vis) return false;
    }
    return true;
}


bool IsEulerCircuit(const vector<vector<int>> G) {
    // 1. is every node has even number edges
    // 2. every two nodes can connect each other 
    bool isEven = true;
    for (int i = 1; i < G.size(); i++) {
        isEven &= G[i].size() % 2 == 0;
    }
    return isEven && IsConnected(G);
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> G(n+1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cout << (IsEulerCircuit(G) ? 1 : 0) << endl;
    return 0;
}