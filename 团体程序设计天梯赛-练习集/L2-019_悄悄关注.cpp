#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	unordered_set<string> names;
	string name;
	int n, m, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		names.insert(name);
	}

	vector<pair<string, int>> ans;
	int tot = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> name >> t;
		tot += t;
		if (names.find(name) == names.end())  
			ans.push_back({name, t});
	}

	float target = tot / m;
	for (auto it = ans.begin(); it != ans.end(); ) {
		if (it->second <= target) it = ans.erase(it);
		else it++;
	}

	if (ans.size() == 0) cout << "Bing Mei You" << endl;
	else {
		sort(ans.begin(), ans.end(), [&](pair<string, int> a, pair<string, int> b) {
			return a.first < b.first;
		});
		for (auto it = ans.begin(); it != ans.end(); it++) {
			cout << it->first << endl;
		}
	}

	return 0;
}