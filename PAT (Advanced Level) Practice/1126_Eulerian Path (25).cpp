#nclude <bits/stdc++.h>
using namespace std;

// 1. 图是连通图
// 2. 奇数度的点为0或2个则是Eulerian
// 3. 所有度为偶数是Semi-Eulerian

vector<int> adj[501];
int main() {
    int n, m, p, q;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &p, &q);
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    int odd_num = 0;
    bool is_circle = true, is_connected = true;

    int cur = 1, tot = 1, vis[501];
    memset(vis, 0, sizeof(int)*501);
    queue<int> Q;
    Q.push(cur);
    vis[cur] = 1;
    while (!Q.empty()) {
        cur = Q.front();
        Q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            if (!vis[adj[cur][i]]) {
                Q.push(adj[cur][i]);
                vis[adj[cur][i]] = 1;
                tot += 1;
            }
        }

    }
    is_connected &= (n == tot);
    
    vector<int> du_list;
    for (int i = 1; i <= n; i++) {
        int du = adj[i].size();
        du_list.push_back(du);
        odd_num += (du % 2 == 1) ? 1 : 0;
        is_circle &= (du % 2 == 0);
    }
    if (du_list.size()>0) printf("%d", du_list[0]);
    for (int i = 1; i < n; i++) 
        printf(" %d", du_list[i]);
    printf("\n");
    if (is_circle && is_connected) printf("Eulerian\n");
    else {
        if (is_connected && (odd_num == 0 || odd_num == 2)) printf("Semi-Eulerian\n");
        else printf("Non-Eulerian\n");
    }
    return 0;
}
