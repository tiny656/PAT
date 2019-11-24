#include <iostream>
#include <vector>
using namespace std;

inline int max(int x, int y) {
    return x > y ? x : y;
}

// 并查集+维护合并后节点数量
class UnionSet {
public:
    vector<int> fa, rank, nodes;

    UnionSet(int n) {
        this->rank.resize(n+1);
        this->fa.resize(n+1);
        this->nodes.resize(n+1); // 记录节点个数
        for (int i = 0; i < n+1; i++) {
            rank[i] = 0;
            fa[i] = i;
            nodes[i] = 1;
        }
    }

    int find(int p) {
        return p == fa[p] ? p : (fa[p] = find(fa[p]));
    }

    int union_set(int p, int q) {
        int i = find(p), j = find(q);
        if (i == j) return nodes[i];
        if (rank[i] < rank[j]) { 
            fa[i] = j; 
            rank[j] += 1;
            nodes[j] += nodes[i];
        } else { 
            fa[j] = i; 
            rank[i] += 1;
            nodes[i] += nodes[j];
        }

        return max(nodes[i], nodes[j]);
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m, p, id;
    cin >> n >> m;
    UnionSet us = UnionSet(n);
    int ans = 1;
    for (int i = 0; i < m; i++) {
        cin >> p;
        int base;
        for (int j = 0; j < p; j++) {
            cin >> id;
            if (j == 0) base = id; 
            else {
                if (!us.connected(base, id)) {
                    ans = max(us.union_set(base, id), ans);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
