#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> G[1005]; // adjacent list(133ms) is better than matrix(246ms) here. 

bool check(const vector<int> &path) {
    int vcnt = path.size();
    vector<int> dis(vcnt+1, 0x3fffffff);
    unordered_map<int, int> min_set;
    dis[path[0]] = 0;
    for (int i = 0; i < vcnt-1; i++) {
        int from = path[i];
        min_set.erase(from); // remove the current seed node
        for (const auto &to : G[from]) {
            if (dis[from] + to.second < dis[to.first]) {
                dis[to.first] = dis[from] + to.second;
                min_set[to.first] = dis[to.first];
            }
        }
        int min_dis = 0x3fffffff;
        for (auto &s : min_set) min_dis = min(min_dis, s.second);

        // if next candidate node not match the minimum distance condition
        if (dis[path[i+1]] != min_dis) return false;
    }

    return true;
}


int main() {
    ios::sync_with_stdio(false);

    int v, e, a, b, d, k;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> d;
        G[a].push_back(make_pair(b, d));
        G[b].push_back(make_pair(a, d));
    }

    vector<int> path(v);
    cin >> k;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < v; j++) cin >> path[j];
        cout << (check(path) ? "Yes" : "No") << endl;
    }

    return 0;
}