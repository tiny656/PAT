#include <bits/stdc++.h>
using namespace std;
/*
1. 邻接矩阵+floyd， O(n^3)第四组用力超时了
2. 邻接表+BFS，从每一个点BFS一遍，找到最大的diameter，用circle数组标记维护friends的关系，遇到circle未被标记的点，circle的num加1
*/
const int N = 1001;
bool circle[N], vis[N];
vector<int> G[N];

int main() {
    int n, k, p;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        circle[i] = false;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            scanf("%d", &p);
            G[i].push_back(p);
            G[p].push_back(i);
        }
    }
    int num = 0;
    int diameter = 0;
    for (int i = 1; i <= n; i++) {
        if (!circle[i]) {
            circle[i] = true;
            num++;
        }
        memset(vis, false, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({i, -1});
        vis[i] = true;
        while (!q.empty()) {
            auto c = q.front(); q.pop();
            diameter = max(diameter, c.second);
            for (auto &it : G[c.first]) {
                if (vis[it]) continue;
                vis[it] = circle[it] = true;
                q.push({it, c.second+1});
            }
        }
    }
    printf("%d %d\n", num, diameter);
    return 0;
}