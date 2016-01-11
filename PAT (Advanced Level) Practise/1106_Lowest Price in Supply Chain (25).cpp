#include <bits/stdc++.h>
using namespace std;
/*小心精度问题，这里队列维护深度整数值*/
int main() {
    int n, c;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c);
        g[i].resize(c);
        for (int j = 0; j < c; j++)
            scanf("%d", &g[i][j]);
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    int dist = 0x7fffffff, nums = 1;
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        if (g[cur.first].empty()) {
            if (cur.second < dist) {
                dist = cur.second;
                nums = 1;
            } else if (cur.second == dist) nums++;
        }
        for (auto &e : g[cur.first])
            q.push({e, cur.second+1});
    }
    printf("%.4f %d\n", p*pow((1.+r/100.), dist), nums);
    return 0;
}
