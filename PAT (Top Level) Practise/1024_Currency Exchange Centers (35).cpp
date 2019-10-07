#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

/*
MST 最小生成树，kruskal算法
贪心选择已经出现过的center
*/
set<string> centers; 

class Edge {
public:
    int c1, c2, fee;
    string center;

    friend bool operator<(const Edge &lhs, const Edge &rhs) {
        if (lhs.fee == rhs.fee) {
            return centers.find(lhs.center) == centers.end();
        } else return lhs.fee > rhs.fee;
    } 
};

class UnionSet {
public:
    int component;
    vector<int> fa, rank;

    UnionSet(int n) {
        component = n;
        fa = vector<int>(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) fa[i] = i;
    }

    int Find(int x) {return fa[x] == x ? x : fa[x] = Find(fa[x]); }

    bool Connected(int p, int q) { return Find(p) == Find(q); }

    void Union(int p, int q) {
        int fp = Find(p);
        int fq = Find(q);
        if (fp == fq) return;
        if (rank[fp] > rank[fq]) fa[fq] = fp;
        else {
            fa[fp] = fq;
            if (rank[fp] == rank[fq]) rank[fq]++;
        }
        component--;
    }
};

int main() {
    int n, m;
    priority_queue<Edge> pq;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.c1 >> e.c2 >> e.center >> e.fee;
        pq.push(e);
    }
    int tot = 0;
    vector<Edge> ans;
    UnionSet us = UnionSet(n);
    while (!pq.empty()) {
        Edge e = pq.top();
        if (!us.Connected(e.c1, e.c2)) {
            us.Union(e.c1, e.c2);
            centers.insert(e.center);
            ans.push_back(e);
            tot += e.fee;
        }
        pq.pop();
    }

    cout << centers.size() << " " << tot << endl;
    sort(ans.begin(), ans.end(), [&](const Edge &e1, const Edge &e2) {
        if (e1.center == e2.center) return e1.fee < e2.fee;
        else return e1.center < e2.center;
    });
    for (auto &v : ans) {
        cout << v.c1 << " " << v.c2 << " " << v.center << " " << v.fee << endl;
    }

    return 0;
}