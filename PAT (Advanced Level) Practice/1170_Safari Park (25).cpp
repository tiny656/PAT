#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	int n, r, k, a, b;
	cin >> n >> r >> k;
	vector<pair<int, int>> edges;
	for (int i = 0; i < r; i++) {
		cin >> a >> b;
		edges.push_back({a, b});
	}

	int m;
	cin >> m;
	while (m--) {
		vector<int> animals(n+1);
		unordered_set<int> s;
		for (int i = 1; i <= n; i++) {
			cin >> animals[i];
			s.insert(animals[i]);
		}

		if (s.size() > (size_t)k) cout << "Error: Too many species." << endl;
		else if (s.size() < (size_t)k) cout << "Error: Too few species." << endl;
		else {
			bool isOk = true;
			for (auto &edge : edges) {
				int animal1 = animals[edge.first];
				int animal2 = animals[edge.second];
				if (animal1 == animal2) {
					cout << "No" << endl;
					isOk = false;
					break;
				}
			}

			if (isOk) cout << "Yes" << endl;
		}
	}

	return 0;
}