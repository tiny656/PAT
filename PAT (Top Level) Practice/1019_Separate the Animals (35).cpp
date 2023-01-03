#include <bits/stdc++.h>
using namespace std;
/*
算法思路：搜索+剪枝
1. 搜索所有可能情况，记录访问过的状态，避免重复搜索（矩阵压缩成二进制位，使用int64表示）
2. 对于找到的可能解，使用floodfill(BFS)进行animal和hole的数量统计，判断当前解是否合法

tips：
1. 原来的写法使用vector<int> path,来记录当前搜索路径，4,6两组用例答案错误，麻蛋的，不知道什么问题
2. 现在的版本全部改成二进制状态来表示
*/
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, k, h;
string row;
bool vis[36];
char grid[6][6];
typedef long long int64;
unordered_set<int64> status;
int64 ans = 0LL;

bool check(int64 node) {
    int holeNum = 0;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int p = i*m+j;
            if (grid[i][j] == 'w' || vis[p] || (node>>p)&1LL) continue;
            bool isHole = true;
            int animalNum = 0;
            queue<int> q;
            q.push(p);
            vis[p] = true;
            while (!q.empty()) {
                p = q.front(); q.pop();
                int cx = p/m, cy = p%m;
                if (cx == 0 || cx == n-1 || cy == 0 || cy == m-1) isHole = false;
                if (grid[cx][cy] == 'O' && ++animalNum > 1) return false;
                for (int i = 0; i < 4; i++) {
                    int x = cx + dx[i], y = cy + dy[i];
                    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 'w' && !vis[x*m+y] && !(node>>(x*m+y)&1LL)) {
                        q.push(x*m+y);
                        vis[x*m+y] = true;
                    }
                }
            }
            if (isHole && ++holeNum > h) return false;
        }
    }
    return holeNum == h;
}

void search(int64 node, int num) {
    if (status.count(node)) return;
    status.insert(node);
    if (num == 0) {
        if (check(node)) ans++;
        return;
    }

    int64 cur = node;
    int cnt = 0, x, y, cx, cy;
    while (cur) {
        if (cur & 1LL) {
            x = cnt / m;
            y = cnt % m;
            for (int i = 0; i < 4; i++) {
                cx = x + dx[i];
                cy = y + dy[i];
                if (cx >= 0 && cy >= 0 && cx < n && cy < m && \
                 grid[cx][cy] == '.' && !((node>>(cx*m+cy))&1LL)) {
                    search(node | (1LL<<(cx*m+cy)), num-1);
                }
            }
        }
        cnt++;
        cur >>= 1LL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> h;
    for (int i = 0; i < n; i++) {
        cin >> row;
        for (int j = 0; j < row.size(); j++) grid[i][j] = row[j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') search(1LL<<(i*m+j), k-1);
        }
    }
    cout << ans << endl;
    return 0;
}