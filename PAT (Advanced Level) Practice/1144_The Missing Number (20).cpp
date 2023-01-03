#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec;
	int n, v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v;
		if (v > 0) vec.push_back(v);
	}
	sort(vec.begin(), vec.end());
	int ans;
	if (vec.empty()) ans = 1;
	else {
		ans = vec[0] - 1 == 0 ? -1 : 1;
		for (int i = 0; i < vec.size() - 1; i++) {
			if (vec[i + 1] - vec[i] >= 2) {
				ans = vec[i] + 1;
				break;
			}
		}
		if (ans == -1) ans = vec[vec.size() - 1] + 1;
	}
	cout << ans << endl;
	return 0;
}