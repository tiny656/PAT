/*
1. 使用二维数组，[节点]-{[0]左孩子,[1]右孩子,[2]节点入度}
2. 根的入度为0
3. 层次遍历判断节点id关系是否连续
*/
#include <bits/stdc++.h>
using namespace std;

int tree[25][3]; // 左，右，入度

int main() {
    int n;
    string str[2];
    cin >> n;

    for (int i = 0; i < n; i++) {
        tree[i][0] = tree[i][1] = -1;
        tree[i][2] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> str[0] >> str[1];
        for (int j = 0; j < 2; j++) {
            if (str[j] != "-") {
                int val = stoi(str[j]);
                tree[i][j] = val;
                tree[val][2]++;
            }
        }
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (tree[i][2] == 0) root = i;
    }

    int previd = 0, ok = true, cur = -1;
    queue<pair<int, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
        int curid = q.front().second;
        cur = q.front().first;
        q.pop();
        if (curid - previd != 1) { ok = false; break; }
        previd = curid;
        if (tree[cur][0] != -1) q.push({tree[cur][0], curid*2});
        if (tree[cur][1] != -1) q.push({tree[cur][1], curid*2 + 1});
    }
    if (ok)
        cout << "YES " << cur << endl;
    else
        cout << "NO " << root << endl;
    return 0;
}