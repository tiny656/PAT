#include <iostream>
#include <vector>
using namespace std;

int FloodFill(vector<vector<int>> &g, vector<bool> &vis) {
	int cnt = 0;
	for (int i = 1; i < g.size(); i++) {
		if (!vis[i]) {
			cnt++;
			vector<int> q;
			q.push_back(i);
			vis[i] = true;
			while (!q.empty()) {
				int u = q.back();
				q.pop_back();
				for (int j = 0; j < g[u].size(); j++) {
					int v = g[u][j];
					if (!vis[v]) {
						q.push_back(v);
						vis[v] = true;
					}
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, k, x, y;
	cin >> n >> m;
	vector<vector<int>> g(n + 1, vector<int>());
	vector<bool> vis(n + 1, false);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> x;
			vis[x] = true;
		}

		int cnt = FloodFill(g, vis);
		fill(vis.begin(), vis.end(), false);
		int remains = g.size() - 1 - n;
		cout << (cnt == remains ? "YES" : "NO") << endl;
	}

	return 0;
}