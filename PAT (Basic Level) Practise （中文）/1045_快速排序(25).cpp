#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
bool ok[maxn];
int num[maxn];
vector<int> ans;
int main() {
    memset(ok, false, sizeof(ok));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &num[i]);
    int tar = num[0];
    for (int i = 0; i < n; i++) {
        tar = max(num[i], tar);
        if (num[i] < tar) ok[i] = true;
    }
    tar = num[n-1];
    for (int i = n-1; i >= 0; i--) {
        tar = min(num[i], tar);
        if (num[i] > tar) ok[i] = true;
    }
    for (int i = 0; i < n; i++)
        if (!ok[i]) ans.push_back(num[i]);
    printf("%d\n", ans.size());
    if (!ans.empty()) {
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); i++)
            printf(" %d",ans[i]);
    }
    // 坑爹的格式
    printf("\n");
    return 0;
}