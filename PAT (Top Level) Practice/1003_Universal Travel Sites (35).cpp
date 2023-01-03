#include<bits/stdc++.h>
using namespace std;
// EK算法的邻接表版本
class Edge {
public:
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f):from(u), to(v), cap(c), flow(f) {}
};

class EdmondsKarp {
public:
    int vertices_num; // 点的数量
    vector<Edge> edges; // 边的集合 
    vector<vector<int>> G; // 邻接表，G[i][j]表示i节点的第j条边在edges中的index
    vector<int> a, p; // a记录第index点到dst的增量

    EdmondsKarp(int n) {
        this->vertices_num = n;
        G.resize(n, {});
        a.resize(n);
        p.resize(n);
    }

    void addEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        int m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    int computeMaxFlow(int src, int dst) {
        int flow = 0;
        for (;;) {
            fill(a.begin(), a.end(), 0);
            queue<int> q;
            q.push(src);
            a[src] = INT_MAX;
            while (!q.empty()) {
                int t = q.front(); q.pop();
                for (int i = 0; i < G[t].size(); i++) {
                    Edge &e = edges[G[t][i]];
                    if (!a[e.to] && e.cap > e.flow) { // a也充当vis数组使用
                        p[e.to] = G[t][i]; // 记录路径
                        a[e.to] = min(a[t], e.cap-e.flow);
                        q.push(e.to);
                    }
                }
                if (a[dst]) break; // 找到一条通往dst的路径，并且可以增广
            }

            if (!a[dst]) break; // bfs后没有找到增广路

            for (int i = dst; i != src; i = edges[p[i]].from) {
                edges[p[i]].flow += a[dst]; // 0和1互为rev，2和3互为rev......
                edges[p[i]^1].flow -= a[dst];
            }
            flow += a[dst]; // 添加本次的增广量
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false);
    string src, dst, x, y;
    int m, c, num = 1; // 如果这里从0开始，注意下面的!nameDict[x]会出问题
    unordered_map<string, int> nameDict;
    cin >> src >> dst >> m;
    EdmondsKarp ek(1005);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        if (!nameDict[x]) nameDict[x] = num++;
        if (!nameDict[y]) nameDict[y] = num++;
        ek.addEdge(nameDict[x], nameDict[y], c);
    }
    cout << ek.computeMaxFlow(nameDict[src], nameDict[dst]);
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

// EK算法的邻接矩阵版本
class EdmondsKarp {
public:
    vector<vector<int>> G; // 邻接矩阵
    vector<int> pre; // 前驱记录
    int vertices_num;

    EdmondsKarp(int n) {
        this->vertices_num = n;
        G.resize(n, vector<int>(n, 0));
        pre.resize(n);
    }

    void addEdge(int x, int y, int c) {
        G[x][y] += c;
    }

    int computeMaxFlow(int src, int dst) {
        int flow = 0, d;
        while (bfs(src, dst)) {
            d = INT_MAX;
            for (int i = dst; i != src; i = pre[i])
                d = min(d, G[pre[i]][i]);
            for (int i = dst; i != src; i = pre[i]) {
                G[pre[i]][i] -= d;
                G[i][pre[i]] += d;
            }
            flow += d;
        }
        return flow;
    }

private:
    bool bfs(int src, int dst) {
        fill(pre.begin(), pre.end(), -1);
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (int i = 0; i < this->vertices_num; i++) {
                if (G[t][i] != 0 && pre[i] == -1) { // pre也充当vis来用
                    pre[i] = t;
                    if (i == dst) return true;
                    q.push(i);
                }
            }
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    unordered_map<string, int> nameDict;
    string src, dst, x, y;
    int m, c, num = 0;
    EdmondsKarp ek(1005);
    cin >> src >> dst >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        if (nameDict.find(x) == nameDict.end()) nameDict[x] = num++;
        if (nameDict.find(y) == nameDict.end()) nameDict[y] = num++;
        ek.addEdge(nameDict[x], nameDict[y], c);
    }
    cout << ek.computeMaxFlow(nameDict[src], nameDict[dst]);
    return 0;
}
