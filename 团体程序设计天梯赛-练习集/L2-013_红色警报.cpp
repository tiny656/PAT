#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int FloodFill(const vector<unordered_set<int>> &g, const unordered_set<int> &removed) {
	vector<bool> visited(g.size(), false);
	int count = 0;
	for (size_t i = 0; i < g.size(); i++) {
		if (removed.find(i) == removed.end() && !visited[i]) {
			count += 1;
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				for (auto w : g[v]) {
					if (!visited[w]) {
						q.push(w);
						visited[w] = true;
					}
				}
			}
		}
	}

	return count;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m, k, a, b, city;
	cin >> n >> m; 
	vector<unordered_set<int>> g(n, unordered_set<int>());
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
	}

	unordered_set<int> removed;
	int prevCount = FloodFill(g, removed);
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> city;
		removed.insert(city);

		g[city].clear();
		for (auto &v : g) v.erase(city);

		int curCount = FloodFill(g, removed);
		if (curCount > prevCount) cout << "Red Alert: City " << city << " is lost!" << endl;
		else cout << "City " << city << " is lost." << endl;
		prevCount = curCount;
		if (i == n-1) cout << "Game Over." << endl;
	}

	return 0;
}