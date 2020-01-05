#include <iostream>
#include <queue>
using namespace std;

// 哈夫曼编码
int main() {
    ios::sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        pq.push(v);
    }

    int ans = 0;
    while (pq.size() != 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a+b;
        ans += c;
        pq.push(c);
    }
    cout << ans << endl;

    return 0;
}