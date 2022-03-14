#include <iostream>
#include <vector>
using namespace std;

int G[205][205];

bool CheckFullConnected(const vector<int> &area) {
    for (int i = 0; i < area.size(); i++) {
        int a = area[i];
        for (int j = i+1; j < area.size(); j++) {
            int b = area[j];
            if (G[a][b] == 0) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, a, b, k, l;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> l;
        vector<int> area(l);
        vector<bool> vis(n+1, false);
        for (int j = 0; j < l; j++) {
            cin >> area[j];
            vis[area[j]] = true;
        }
        bool isFullConnected = CheckFullConnected(area);
        if(!isFullConnected) cout << "Area " << i << " needs help." << endl;
        else {
            bool findExtra = false;
            for (int j = 1; j <= n; j++) {
                if (!vis[j]) {
                    area.push_back(j);
                    isFullConnected = CheckFullConnected(area);
                    area.pop_back();
                    if (isFullConnected) {
                        cout << "Area " << i << " may invite more people, such as "<< j << "." << endl;
                        findExtra = true;
                        break;
                    }
                }
            }
            if (!findExtra) cout << "Area " << i << " is OK." << endl;
        }
    }
    return 0;
} 