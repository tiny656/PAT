#include <bits/stdc++.h>
using namespace std;
// 最小生成树算法, 并查集 + kruskal
// 1. 并查集维护components的数量，成功union两个不连接的节点，components减1
// 2. 如何判断唯一性？如果当前存在大于等于2种相同权重边可以选择，这些边都能够将compents数量减1,那么如果是唯一的MST，它们都应该出现在最终的MST里，所以当遇到多种相同权重边被标记应该出现MST中，但是后续发现这类的其中某一条边的两个顶点已经被union了，所以这时候MST是不唯一的。

class UnionSet {
public:
    int num;
    vector<int> fa, rank;

    UnionSet(int n) {
        this->num = n;
        this->rank.resize(n+1);
        this->fa.resize(n+1);
        for (int i = 0; i < n+1; i++) {
            rank[i] = 0;
            fa[i] = i;
        }
    }

    int find(int p) {
        return p == fa[p] ? p : (fa[p] = find(fa[p]));
    }

    void union_set(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return;
        this->num--;
        if (rank[i] < rank[j]) { fa[i] = j; rank[j] += 1;}
        else { fa[j] = i; rank[i] += 1; }
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};

class Edge {
public:
    int v1, v2, w;
    bool status;
    Edge(int v1, int v2, int w) {
        this->v1 = v1;
        this->v2 = v2;
        this->w = w;
        this->status = false;
    }

    bool operator<(const Edge &e) const {
        return this->w < e.w;
    }
};

int main() {
    vector<Edge> edge_vec;
    int n, m, v1, v2, w;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &v1, &v2, &w);
        edge_vec.push_back(Edge(v1, v2, w));
    }
    sort(edge_vec.begin(), edge_vec.end());
    auto u = UnionSet(n);
    bool isUnique = true;
    int sum = 0;
    for (int i = 0; i < edge_vec.size(); i++) {
        auto e = edge_vec[i];
        if (u.connected(e.v1, e.v2)) {
            if (e.status) isUnique = false;
            continue;
        } else {
            int p = i;
            while (p < edge_vec.size() && edge_vec[p].w == e.w && !u.connected(edge_vec[p].v1, edge_vec[p].v2))
                edge_vec[p++].status = true;
            u.union_set(e.v1, e.v2);
            sum += e.w;
        }
    }
    if (u.num != 1) printf("No MST\n%d\n", u.num);
    else printf("%d\n%s\n", sum, isUnique ? "Yes" : "No");
    return 0;
}