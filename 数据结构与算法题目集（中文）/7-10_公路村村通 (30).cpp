#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

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
        if (!u.connected(e.v1, e.v2)) {
            int p = i;
            u.union_set(e.v1, e.v2);
            sum += e.w;
        }
    }
    if (u.num != 1) printf("-1\n");
    else printf("%d\n", sum);
}