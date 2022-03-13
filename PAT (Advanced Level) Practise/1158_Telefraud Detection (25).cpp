#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int G[1005][1005];

void search(int seed, vector<pair<int, bool>> &suspects, vector<int> &gang) {
    for (auto &s : suspects) {
        if (s.second || seed == s.first) continue;
        if (G[seed][s.first] > 0 && G[s.first][seed] > 0) {
            s.second = true;
            gang.push_back(s.first);
            search(s.first, suspects, gang);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    fill(G[0], G[0] + 1005 * 1005, 0);
    int k, n, m, caller, receiver, duration;
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> caller >> receiver >> duration;
        G[caller][receiver] += duration;
    }

    vector<pair<int, bool>> suspects;
    for (int i = 1; i <= n; i++) {
        int c1 = 0, c2 = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (G[i][j] > 0 && G[i][j] <= 5) {
                c1++;
                if (G[j][i] > 0) c2++; 
            }
        }

        if (c1 > k && c2 * 5 <= c1) {
            suspects.push_back(make_pair(i, false));
        }
    }

    if (suspects.size() == 0) cout << "None" << endl;
    else {
        for (auto &s : suspects) {
            if (s.second) continue;

            vector<int> gang;
            s.second = true;
            gang.push_back(s.first);
            search(s.first, suspects, gang);
            sort(gang.begin(), gang.end());

            if (gang.size() > 0) {
                cout << gang[0];
                for (int i = 1; i < gang.size(); i++) cout << " " << gang[i];
                cout << endl;
            }
        }
    }

    return 0;
}