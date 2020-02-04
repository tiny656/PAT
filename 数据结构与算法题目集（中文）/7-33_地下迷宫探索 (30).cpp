#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt = 0;

void dfs(int n, const vector<vector<int>> &G, vector<bool> &isVis, vector<int> &ans) {
    ans.push_back(n);
    for (int i = 0; i < G[n].size(); i++) {
        if (!isVis[G[n][i]]) {
            isVis[G[n][i]] = true;
            cnt++;
            dfs(G[n][i], G, isVis, ans);
            ans.push_back(n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, s, a, b;
    cin >> n >> m >> s;
    vector<bool> isVis(n+1, false);
    vector<vector<int>> G(n+1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
    vector<int> ans;
    isVis[s] = true;
    cnt++;
    dfs(s, G, isVis, ans);
    if (cnt < n) ans.push_back(0);
    for (int i = 0; i < ans.size(); i++) {
        if (i == 0) cout << ans[i];
        else cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}