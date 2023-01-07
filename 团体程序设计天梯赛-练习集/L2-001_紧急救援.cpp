#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

void PrintPath(int src, int city, unordered_map<int,int> pre) {
    if (city == src) {
        cout << src;
        return;
    }
    PrintPath(src, pre[city], pre);
    cout << " " << city;
}

struct Node {
    int city, dist, rescue;
    Node(int city, int dist, int rescue) : city(city), dist(dist), rescue(rescue) {}
    bool operator<(const Node &rhs) const {
        if (dist == rhs.dist) rescue < rhs.rescue;
        else return dist > rhs.dist;
    }
};

int main() {
    int n, m, src, dest;
    cin >> n >> m >> src >> dest;
    vector<int> r(n);
    vector<vector<pair<int, int>>> G(n, vector<pair<int, int>>());
    for (int i = 0; i < n; i++) cin >> r[i];
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        G[u].push_back({v, d});
        G[v].push_back({u, d});
    }

    vector<int> dist(n, 0x3fffffff), pathCnt(n, 0), rescue(n, 0), vis(n, false);
    priority_queue<Node> q = priority_queue<Node>();
    unordered_map<int, int> pre;
    pre[src] = src;
    rescue[src] = r[src];
    pathCnt[src] = 1;
    dist[src] = 0;
    q.push(Node{src, 0, r[src]});

    while (!q.empty()) {
        Node u = q.top();
        q.pop();

        if (vis[u.city]) continue;
        vis[u.city] = true;

        for (auto &p : G[u.city]) {
            int v = p.first, d = p.second;
            if (dist[u.city] + d < dist[v]) {
                dist[v] = dist[u.city] + d;
                rescue[v] = rescue[u.city] + r[v];
                pre[v] = u.city;
                pathCnt[v] = pathCnt[u.city];
                q.push({v, dist[v], rescue[v]});
            } else if (dist[u.city] + d == dist[v]) {
                if (r[v] + rescue[u.city] > rescue[v]) {
                    rescue[v] = rescue[u.city] + r[v];
                    pre[v] = u.city;
                    q.push({v, dist[v], rescue[v]});
                }
                pathCnt[v] += pathCnt[u.city];
            }
        }
    }

    cout << pathCnt[dest] << " " << rescue[dest] << endl;
    PrintPath(src, dest, pre);
    cout << endl;
}
