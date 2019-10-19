#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
using namespace std;

const int maxn = 505;
int noteMoney[maxn], dist[maxn], path[maxn];

struct Edge {
    int to;
    int money;
    int len;
    bool operator < (const Edge &a) const {
        if (a.len == len)
            return money > a.money;
        return len > a.len;
    }
} temp, cur;

vector<Edge> AdjList[maxn];

/*BFS+Priority_Queue*/
void BFS(int s,int d) {
    priority_queue<Edge> pq;
    temp.len = 0;
    temp.money = 0;
    temp.to = s;
    noteMoney[temp.to] = 0;
    dist[temp.to] = 0;
    pq.push(temp);
    path[s] = -1;
    while(!pq.empty()) {
        temp = pq.top();
        if(temp.to == d) {
            stack<int> ans;
            int pp = temp.to;
            while(pp != -1) {
                ans.push(pp);
                pp = path[pp];
            }
            while(!ans.empty()) ans.pop();
            printf("%d %d\n", temp.len, temp.money);
            return;
        }
        pq.pop();
        for (int i = 0; i < AdjList[temp.to].size(); i++) {
            cur = AdjList[temp.to][i];
            cur.money += temp.money;
            cur.len += temp.len;
            if(cur.len < dist[cur.to]) {
                dist[cur.to] = cur.len;
                noteMoney[cur.to] = cur.money;
                path[cur.to] = temp.to;
                pq.push(cur);
            } else if(cur.len == dist[cur.to] && noteMoney[cur.to] > cur.money) {
                noteMoney[cur.to] = cur.money;
                path[cur.to] = temp.to;
                pq.push(cur);
            }
        }
    }
}

int main() {
    int n, fee, r, i, s, d, l, t, start, end;
    scanf("%d %d %d %d", &n, &r, &start, &end);
    for (i = 1; i <= r; i++) {
        scanf("%d %d %d %d", &s, &d, &l, &t);
        temp.to = d;
        temp.len = l;
        temp.money = t;
        AdjList[s].push_back(temp);
        temp.to = s;
        temp.len = l;
        temp.money = t;
        AdjList[d].push_back(temp);
    }

    for (i = 0; i < n; i++) {
        noteMoney[i] = 10000000;
        dist[i] = 10000000;
    }

    BFS(start,end);

    return 0;
}