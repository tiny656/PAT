#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
#define min(a, b) (a < b ? a : b)

int main() {
	ios::sync_with_stdio(false);
	int n, k, tag;
	string name;
	vector<tuple<int, float, string>> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> k;
		unordered_set<int> tags;
		for (int j = 0; j < k; j++) {
			cin >> tag;
			tags.insert(tag);
		}
		int cnt = tags.size();
		float avg = k / (float)tags.size();
		ans.push_back({cnt, avg, name});
	}

	sort(ans.begin(), ans.end(), [&](tuple<int, float, string> a, tuple<int, float, string> b) {
		if (get<0>(a) == get<0>(b))
			return get<1>(a) < get<1>(b);
		else return get<0>(a) > get<0>(b);
	});

	if (ans.size() == 0) cout << "- - -" << endl;
	else {
		cout << get<2>(ans[0]);
		int len = min(3, ans.size());
		for (int i = 1; i < len; i++)
			cout << " " << get<2>(ans[i]);
		for (int i = 0; i < 3 - len; i++) 
			cout << " -";
		cout << endl;
	}

	return 0;
}