#include <bits/stdc++.h>
using namespace std;
/*
读入数据，排序，随后while循环模拟旋转进行填充

 */
int main() {
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int row = 1, col = 1;
    int minDiff = 10005;
    for (int i = 1; i < n/2+1; i++) {
        if (n % i == 0 && abs(n/i-i) < minDiff) {
            minDiff = abs(n/i-i);
            row = n/i;
            col = i;
        }
    }
    vector<vector<int>> mat(row);
    for (auto &r : mat) r.resize(col);
    int x = 0, y = 0, idx = 0;
    while (idx < n) {
        while (idx < n and y < col and mat[x][y] == 0) {
            mat[x][y] = v[idx];
            y += 1;
            idx += 1;
        }
        x = x+1; y = y-1;
        while (idx < n and x < row and mat[x][y] == 0) {
            mat[x][y] = v[idx];
            x += 1;
            idx += 1;
        }
        x = x-1; y = y-1;
        while (idx < n and y >= 0 and mat[x][y] == 0) {
            mat[x][y] = v[idx];
            y -= 1;
            idx += 1;
        }
        x = x-1; y = y+1;
        while (idx < n and x >= 0 and mat[x][y] == 0) {
            mat[x][y] = v[idx];
            x -= 1;
            idx += 1;
        }
        x = x+1; y = y+1;
    }
    for (int i = 0; i < row; i++) {
        cout << mat[i][0];
        for (int j = 1; j < col; j++)
            cout << " " << mat[i][j];
        cout << endl;
    }
    return 0;
}
/*
12
37 76 20 98 76 42 53 95 60 81 58 93
 */