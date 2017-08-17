#include <bits/stdc++.h>
using namespace std;

// 加优先级队列的dijsktra，需要两个dist，另一个维护第一个dist距离更新时候相等情况

struct Node {
    int id, val;
    Node(int id, int val) {
        this->id = id;
        this->val = val;
    }
};

bool operator <(const Node& a, const Node& b) {
    if (a.val == b.val) return a.id < b.id;
    return a.val > b.val;
}

const int MAXN = 500;
priority_queue<Node> pq;
int dist1[MAXN], dist2[MAXN], vis[MAXN], fa[MAXN];

vector<tuple<int,int,int>> adj[MAXN];

tuple<int, string> dijsktra(int n, int src, int dst, bool t=false) {
    fill(dist1, dist1+n, 0x7fffffff);
    fill(dist2, dist2+n, 0x7fffffff);
    fill(vis, vis+n, false);
    fa[src] = -1;
    pq.push(Node(src, 0));
    dist1[src] = dist2[src] = 0;
    while (!pq.empty()) {
        Node c = pq.top(); pq.pop();
        vis[c.id] = true;
        if (c.val > dist1[c.id]) continue;
        for (const tuple<int, int, int> &nxt : adj[c.id]) {
            auto nxt_id = get<0>(nxt);
            auto nxt_len = get<1>(nxt);
            auto nxt_time = get<2>(nxt);
            if (vis[nxt_id]) continue;
            if (t && (dist1[nxt_id] > dist1[c.id] + nxt_time || (dist1[nxt_id] == dist1[c.id] + nxt_time && dist2[nxt_id] > dist2[c.id] + 1))) {
                    dist1[nxt_id] = dist1[c.id] + nxt_time;
                    dist2[nxt_id] = dist2[c.id] + 1;
                    fa[nxt_id] = c.id;
                    pq.push(Node(nxt_id, dist1[nxt_id]));
            } else if (!t && (dist1[nxt_id] > dist1[c.id] + nxt_len || (dist1[nxt_id] == dist1[c.id] + nxt_len && dist2[nxt_id] > dist2[c.id] + nxt_time))) {
                    dist1[nxt_id] = dist1[c.id] + nxt_len;
                    dist2[nxt_id] = dist2[c.id] + nxt_time;
                    fa[nxt_id] = c.id;
                    pq.push(Node(nxt_id, dist1[nxt_id]));
            }
        }
    }
    int c = fa[dst];
    string path = to_string(dst);
    while (c != -1) {
        path = to_string(c) + " -> " + path;
        c = fa[c];
    }
    return make_tuple(dist1[dst], path);
}

int main() {
    int n, m, v1, v2, oneway, len, time;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d%d", &v1, &v2, &oneway, &len, &time);
        adj[v1].push_back(tuple<int, int, int>(v2, len, time));
        if (!oneway) adj[v2].push_back(tuple<int, int, int>(v1, len, time));
    }
    scanf("%d%d", &v1, &v2);
    auto dis_res = dijsktra(n, v1, v2);
    auto time_res = dijsktra(n, v1, v2, true);
    if (get<1>(dis_res) == get<1>(time_res)) 
        printf("Distance = %d; Time = %d: %s\n", get<0>(dis_res), get<0>(time_res), get<1>(dis_res).c_str());
    else
        printf("Distance = %d: %s\nTime = %d: %s\n", get<0>(dis_res), get<1>(dis_res).c_str(), get<0>(time_res), get<1>(time_res).c_str());
    return 0;
}
