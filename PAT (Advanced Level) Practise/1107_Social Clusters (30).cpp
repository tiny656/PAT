#include <bits/stdc++.h>
using namespace std;

/*
使用图邻接表的方式，Person的点范围为0-1000,Hobby添加一个1000的Offset偏移。
构造无向图，接着使用Floodfill，记录一个子图的所有不超过Offset的点，即为一个社交群体人数。
 */
const int OFFSET = 1000;
unordered_map<int, vector<int>> g;
unordered_map<int, bool> vis;

int floodfill(int id) {
    int cnt = 0;
    queue<int> q;
    q.push(id);
    vis[id] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur < OFFSET) cnt++;
        for (const auto &v : g[cur]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return cnt;
}

int main() {
    int n, k, h;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &h);
            g[i].push_back(h+OFFSET);
            g[h+OFFSET].push_back(i);
        }
    }
    vector<int> ans;
    for (const auto &v: g) {
        if (v.first < OFFSET && !vis[v.first])
            ans.push_back(floodfill(v.first));
    }
    sort(ans.begin(), ans.end(), greater<int>());
    printf("%d\n", ans.size());
    if (!ans.empty()) {
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
