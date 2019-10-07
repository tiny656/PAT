#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

/* MST 最小生成树，Kruskal算法*/
class Edge {
public:
    int s, t, w;
    friend bool operator<(const Edge &lhs, const Edge &rhs) {
        return lhs.w > rhs.w;   
    }
};

class UnionSet {
public:
    vector<int> fa, rank;
    int component;

    UnionSet(int n) {
        component = n;
        fa = vector<int>(n+1);
        rank = vector<int>(n+1, 0);
        for (int i = 0; i <= n ;i++) fa[i] = i;
    }

    int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }

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
    int n, ok;
    scanf("%d", &n);
    UnionSet us = UnionSet(n);

    Edge e = Edge();
    priority_queue<Edge> pq;
    for (int i = 0; i < n*(n-1)/2; i++) {
        scanf("%d %d %d %d", &e.s, &e.t, &e.w, &ok);
        ok ? us.Union(e.s, e.t) : pq.push(e);
    }

    int ans = 0;
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if(!us.Connected(e.s, e.t)) {
            ans += e.w;
            us.Union(e.s, e.t);
        }
    }
    printf("%d\n", ans);

    return 0;
}