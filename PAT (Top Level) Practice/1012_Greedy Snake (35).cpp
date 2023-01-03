#include <bits/stdc++.h>
using namespace std;
/*
因为n很小，所以深搜+回溯寻找所有可能情况
对于添加一个obstacle采用枚举，然后继续重复第一次的深搜+回溯方法
*/
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n;
int mat[15][15];

enum State {Brick=-1, Empty, Start, Visit};

bool isValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return false;
    if (mat[x][y] == Brick || mat[x][y] == Start || mat[x][y] == Visit) return false;
    return true;
}

int search(int x, int y) {
    int ret = 0;
    for (int di = 0; di < 4; di++) {
        int cnt = 1;
        while (isValid(x+dx[di]*cnt, y+dy[di]*cnt)) {
            mat[x+dx[di]*cnt][y+dy[di]*cnt] = Visit;
            cnt++;
        }
        if (cnt == 1) continue;
        cnt--;
        ret = max(ret, search(x+dx[di]*cnt, y+dy[di]*cnt)+cnt);
        for (int i = 1; i <= cnt; i++) mat[x+dx[di]*i][y+dy[di]*i] = Empty;
    }
    return ret;
}

int main() {
    int k, x, y;
    scanf("%d%d", &n, &k);
    // init matrix
    memset(mat, Empty, sizeof(mat));
    for (int i = 0; i < n; i++) mat[0][i] = mat[n-1][i] = mat[i][0] = mat[i][n-1] = Brick;
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x, &y);
        mat[x-1][y-1] = Brick;
    }

    int minRemain = n*n, minRemainNum = 0;
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (!isValid(i, j)) continue;
            mat[i][j] = Start;
            int remain = (n-2)*(n-2)-k-search(i, j)-1;
            minRemainNum = remain < minRemain ? 1 : (minRemainNum + (minRemain == remain ? 1 : 0));
            minRemain = min(minRemain, remain);
            mat[i][j] = Empty;
        }
    }
    printf("%d %d\n", minRemain, minRemainNum);

    int newMinRemain = n*n;
    set<int> obstacleWays;
    for (int bi = 1; bi < n-1; bi++) {
        for (int bj = 1; bj < n-1; bj++) {
            if (!isValid(bi, bj)) continue;
            mat[bi][bj] = Brick;
            for (int i = 1; i < n-1; i++) {
                for (int j = 1; j < n-1; j++) {
                    if (!isValid(i, j)) continue;
                    mat[i][j] = Start;
                    int remain = (n-2)*(n-2)-k-search(i, j)-2;
                    if (remain <= newMinRemain) {
                        if (remain < newMinRemain) obstacleWays.clear();
                        newMinRemain = remain;
                        obstacleWays.insert(n*bi+bj);
                    }
                    mat[i][j] = Empty;
                }
            }
            mat[bi][bj] = Empty;
        }
    }
    if (newMinRemain >= minRemain) printf("-1\n");
    else printf("%d %d\n", newMinRemain, obstacleWays.size());

    return 0;
}