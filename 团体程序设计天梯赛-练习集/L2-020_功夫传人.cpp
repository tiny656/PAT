#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(const vector<vector<int>> &p, const vector<int> &isMaster, int id, double &ans, double power, double r) {
	if (abs(isMaster[id]) > 1e-3) {
		ans += isMaster[id] * power;
		return;
	}
	for (int i = 0; i < p[id].size(); i++) {
		DFS(p, isMaster, p[id][i], ans, power * (1 - r / 100.), r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, k, id;
	double z, r, x;
	cin >> n >> z >> r;

	vector<vector<int>> p(n, vector<int>());
	vector<int> isMaster(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 0) {
			cin >> x;
			isMaster[i] = x;
		} else {
			for (int j = 0; j < k; j++) {
				cin >> id;
				p[i].push_back(id);
			}
		}
	}
	double ans = 0;
	DFS(p, isMaster, 0, ans, z, r);
	cout << (int)ans << endl;
	return 0;
}