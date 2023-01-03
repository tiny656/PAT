#include <bits/stdc++.h>
using namespace std;
/*
强连通分量，Tarjan算法
*/
const int N = 10000;
vector<int> edges[N*6+5];
stack<int> s;
int dfn[N+5], low[N+5], scc[N+5];
bool inStack[N+5];
int dfnIndex = 0, sccIndex = 0;

void tarjan(int u) {
    dfn[u] = low[u] = ++dfnIndex;
    inStack[u] = true;
    s.push(u);
    for (auto &v : edges[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        } else if (inStack[v] && dfn[v] < low[u]) {
            low[u] = dfn[v];
        }
    }
    if (low[u] == dfn[u]) {
        sccIndex++;
        int tmp = 0;
        while (tmp != u) {
            tmp = s.top(); s.pop();
            scc[tmp] = sccIndex;
            inStack[tmp] = false;
        }
    }
}


int main() {
    int n, m, k, u, v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        edges[u].push_back(v);
    }
    memset(inStack, false, sizeof(inStack));
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &u, &v);
        printf("%s\n", scc[u] == scc[v] ? "Yes" : "No");
    }
    return 0;
}