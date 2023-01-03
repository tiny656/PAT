#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
vector<int> adjList[maxn];
int main() {
    int n, v, root;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    // 预处理出，边邻接表，保存root
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        adjList[v].push_back(i);
        if (v == -1) root = i;
    }
    // 从root开始BFS，并标记每层深度，i记录最深的节点和数量
    int max_dep = 0, max_dep_cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        pair<int, int> p = q.front();
        int cur = p.first, dep = p.second;
        q.pop();
        if (dep > max_dep) {
            max_dep = dep;
            max_dep_cnt = 1;
        }
        else if (dep == max_dep) {
            max_dep_cnt += 1;
        }
        for (int i = 0; i < adjList[cur].size(); i++)
            q.push(make_pair(adjList[cur][i], dep + 1));
    }
    printf("%.2lf %d\n", p*pow((1 + r / 100), max_dep), max_dep_cnt);
    return 0;
}