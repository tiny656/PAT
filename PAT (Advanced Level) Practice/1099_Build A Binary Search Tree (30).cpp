#include <bits/stdc++.h>
using namespace std;

// 先排序，中序遍历恢复出节点上的值
// 层次遍历输出最终结果值
struct Node {
    int left, right;
    int val;
}nodeList[105];
int n, val[105], len = 0;

void dfs(int x) {
    if (x != -1 &&x < n) {
        dfs(nodeList[x].left);
        nodeList[x].val = val[len++];
        dfs(nodeList[x].right);
    }
}

int main() {
    int root = 0, l, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &l, &r);
        nodeList[i].left = l;
        nodeList[i].right = r;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    sort(val, val+n);
    dfs(root);
    queue<int> q;
    printf("%d", nodeList[root].val);
    if (nodeList[root].left != -1) q.push(nodeList[root].left);
    if (nodeList[root].right != -1) q.push(nodeList[root].right);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        printf(" %d", nodeList[cur].val);
        if (nodeList[cur].left != -1) q.push(nodeList[cur].left);
        if (nodeList[cur].right != -1) q.push(nodeList[cur].right);
    }
    puts("");
    return 0;
}
/*
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
*/