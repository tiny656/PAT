#include <bits/stdc++.h>
using namespace std;

// 图邻接表 + bfs 遍历统计


vector<int> adj[105];
int generation[105];

int main(int argc, char const *argv[]) {
    int n, m, id, child, k;
    scanf("%d%d", &n, &m);
    while (m--) {
        scanf("%d%d", &id, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &child);
            adj[id].push_back(child);
        }
    }
    int depth = 0, maxPopulation = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    while (!q.empty()) {
        auto curNode = q.front();
        q.pop();
        generation[curNode.second]++;
        if (maxPopulation < generation[curNode.second]) {
            maxPopulation = generation[curNode.second];
            depth = curNode.second;
        }
        for (int i = 0; i < adj[curNode.first].size(); i++) {
            q.push({adj[curNode.first][i], curNode.second+1});
        }
    }
    printf("%d %d\n", maxPopulation, depth);
    return 0;
}