#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string  GetTSTypeString(int tsType)  {
    if (tsType == 0) return "TS simple cycle";
    else if (tsType == 1) return "TS cycle";
    else if (tsType == 2) return "Not a TS cycle";
}

pair<int, int> CalcDistance(const int dist[][201], int n, const vector<int> &path) {
    vector<int> count(n+1);
    for (const auto &v : path) {
        count[v] += 1;
    }
    int tsType = path[0] != path[path.size()-1] ? 2 : 0; // 0 ts simple 1 ts 2 not ts 
    for (int i = 1; i <= n && tsType == 0; i++) {
        if (count[i] == 0) {
            tsType = 2;
        } else if (count[i] > 1 && i != path[0]) {
            tsType = 1;
        }
    }
    int d = 0;
    for (int i = 0; i < path.size()-1; i++) {
        if (dist[path[i]][path[i+1]] == -1) {
            d = -1;
            tsType = 2;
            break;
        } else {
            d += dist[path[i]][path[i+1]];
        }
    }
    return {d, tsType};
}

int main() {
    int N, M, c1, c2, d, k, n;
    int dist[201][201];
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dist[i][j] = -1;
        }
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        cin >> c1 >> c2 >> d;
        dist[c1][c2] = dist[c2][c1] = d;
    }
    cin >> k;
    pair<int, int> shortest = {-1, 0x7fffffff};
    for (int i = 0; i < k; i++) {
        cin >> n;
        vector<int> C(n);
        for (int j = 0; j < n; j++) {
            cin >> C[j];
        }
        pair<int,int> r = CalcDistance(dist, N, C);
        cout << "Path " << i+1 << ": ";
        if (r.first == -1) cout << "NA";
        else cout << r.first;
        cout << " (" << GetTSTypeString(r.second) << ")" << endl;
        if ((r.second == 0 || r.second == 1) && r.first < shortest.second) {
            shortest.first = i + 1;
            shortest.second = r.first;
        }
    }
    cout << "Shortest Dist(" << shortest.first << ") = " << shortest.second << endl;
    return 0;
}