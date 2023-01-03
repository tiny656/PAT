#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> G[10000]; // 邻接表
int color[10000];
unordered_map<int, bool> isVis;

int main() {
    ios::sync_with_stdio(false);
    int n, m, a, b, k;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int numOfColor = 0;
        isVis.clear();
        for (int j = 0; j < n; j++) {
            cin >> color[j];
            if (!isVis[color[j]]) {
                isVis[color[j]] = true;
                numOfColor += 1;
            }
        }
        bool isOk = true;
        for (int n1 = 0; n1 < n; n1++) {
            for (const auto &n2 : G[n1]) {
                if (color[n1] == color[n2]) {
                    isOk = false; break;
                }
            }
            if (!isOk) break;
        }
        if (isOk) cout << numOfColor << "-coloring" << endl;
        else cout << "No" << endl;
    }
    return 0;
}