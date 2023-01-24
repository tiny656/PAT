#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int v, e, k, a, b, n;
	cin >> v >> e >> k;
	vector<pair<int, int>> edges;
	for (int i = 0; i < e; i ++) {
		cin >> a >> b;
		edges.push_back({a, b});
	}
	cin >> n;
	for (int i = 0; i < n; i ++) {
		vector<int> colors(v+1);
		unordered_set<int> colorSet;
		for (int j = 1; j <= v; j ++) {
			cin >> colors[j];
			colorSet.insert(colors[j]);
		}
		bool isOk = true && colorSet.size() == k;
		for (int j = 0; j < edges.size() && isOk; j++) {
			if (colors[edges[j].first] == colors[edges[j].second]) {
				isOk = false;
			}
		}
		if (isOk) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}