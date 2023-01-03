#include <bits/stdc++.h>
using namespace std;
/*
Flood Fill(BFS) 方法
*/
int matrix[60][1286][128]; // 三维切片空间
// 空间6方向
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
// 切片行，列， 切片数量
int m, n, l;
// 元素索引
class Point {
public:
    int id; // slice id
    int x; // pos x
    int y; // pos y
    Point(int id, int x, int y) :id(id), x(x), y(y) {}
};

// FloodFill(BFS)遍历标记所有元素
int getVolume(const Point &seed) {
    queue<Point> q;
    q.push(seed);
    int ret = 1;
    matrix[seed.id][seed.x][seed.y] = 0;
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        matrix[p.id][p.x][p.y] = 0;
        for (int i = 0; i < 6; i++) {
            int id = p.id + dx[i];
            int x = p.x + dy[i];
            int y = p.y + dz[i];
            if (id >= 0 && id < l && x >= 0 && x < m && y >= 0 && y < n && matrix[id][x][y]) {
                q.push(Point(id, x, y));
                ret += 1;
                matrix[id][x][y] = 0;
            }
        }
    }
    return ret;
}

int main() {
    int t;
    vector<Point> potentialCorePos; // 预处理存储1元素的索引坐标
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int id = 0; id < l; id++)
    for (int x = 0; x < m; x++)
    for (int y = 0; y < n; y++) {
        scanf("%d", &matrix[id][x][y]);
        if (matrix[id][x][y]) potentialCorePos.push_back(Point(id, x, y));
    }
    int ans = 0;
    for (int i = 0; i < potentialCorePos.size(); i++) {
        Point p = potentialCorePos[i];
        if (matrix[p.id][p.x][p.y]) {
            int tot = getVolume(p);
            if (tot >= t) ans += tot;
        }
    }
    printf("%d\n", ans);
    return 0;
}