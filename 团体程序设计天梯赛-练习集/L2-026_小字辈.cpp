#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, fa, root = 0;
    cin >> n;
    vector<vector<int>> trees(n+1, vector<int>());
    vector<vector<int>> levels;

    for (int i = 1; i <= n; i++) {
        cin >> fa;
        if (fa == -1) {
            root = i;
            continue;
        }
        trees[fa].push_back(i);
    }

    queue<pair<int,int>> q;
    levels.push_back(vector<int>{root});
    q.push({root, 0});

    while (!q.empty()) {
        int node = q.front().first;
        int level = q.front().second;
        q.pop();
        for (int child : trees[node]) {
            if (levels.size() <= (size_t)level+1) levels.push_back(vector<int>());
            levels[level+1].push_back(child);
            q.push({child, level+1});
        }
    }

    cout << levels.size()<< endl;
    cout << levels[levels.size()-1][0];
    for (size_t i = 1; i < levels[levels.size()-1].size(); i++)
        cout << " " << levels[levels.size()-1][i];
    cout << endl;

    return 0;
}