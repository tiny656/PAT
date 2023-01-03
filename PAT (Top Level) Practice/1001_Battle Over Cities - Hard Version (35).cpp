#include <bits/stdc++.h>
using namespace std;
// 并查集 + kruskal
// 枚举要去除的城市，再计算最小生成树
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
        if (p == fa[p]) return p;
        else fa[p] = find(fa[p]);
        return fa[p];
    }

    void union_set(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) return;
        if (rank[i] < rank[j]) { fa[i] = j; rank[j] += 1;}
        else { fa[j] = i; rank[i] += 1; }
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

};

class Edge {
public:
    int p, q, cost, status;
    Edge(int p, int q, int cost, int status) {
        this->p = p;
        this->q = q;
        this->cost = cost;
        this->status = status;
    }

    bool operator<(const Edge &e) const {
        if (e.status == this->status)
            return this->cost < e.cost;
        else return this->status > e.status; 
    }
     
};

int compute_rebuild_cost(int city_num, int destroy_city, const vector<Edge> &edge_vec) {
    // kruskal
    auto u = UnionSet(city_num);
    int edge_num = 0, cost = 0;
    for (int i = 0; i < edge_vec.size() && edge_num < city_num-2; i++) {
        int p = edge_vec[i].p;
        int q = edge_vec[i].q;
        if (p != destroy_city && q != destroy_city && !u.connected(p, q)) {
            u.union_set(p, q);
            cost += edge_vec[i].status == 0 ? edge_vec[i].cost : 0;
            edge_num++;
        }
    }
    return edge_num == city_num-2 ? cost : 0x7fffffff;
}


int main() {
    vector<Edge> edge_vec;
    int n, m, p, q, cost, status;
    int max_cost = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &p, &q, &cost, &status);
        edge_vec.push_back(Edge(p, q, cost, status));
    }
    sort(edge_vec.begin(), edge_vec.end());
    vector<int> city_rebuild_cost;
    city_rebuild_cost.resize(n+1);
    for (int i = 1; i <= n; i++) {
        city_rebuild_cost[i] = compute_rebuild_cost(n, i, edge_vec);
        max_cost = max(max_cost, city_rebuild_cost[i]);
    }
    if (max_cost == 0)  printf("0\n");
    else {
        bool isFirst = true;
        for (int i = 1; i <= n; i++ ) {
            if (max_cost == city_rebuild_cost[i]) {
                if (isFirst) {
                    printf("%d", i);
                    isFirst = false;
                }
                else printf(" %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}

