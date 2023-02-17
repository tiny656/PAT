#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	unordered_set<int> s, out;
	int a, b, n, m;
	cin >> a >> b;
	s.insert(a);
	s.insert(b);
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	// for loop by round
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			// if player i is out, skip
			if (out.find(i) != out.end()) continue; 

			int t = v[i][j];
			// if t is in s, player i is out
			if (s.find(t) != s.end()) {
				cout << "Round #" << j + 1 << ": " << i+1 << " is out." << endl;
				out.insert(i);
			} else {
				// if t is not in s, check if t + any element in s is in s
				bool isValid = false;
				for (auto it = s.begin(); it != s.end(); it++) {
					if (s.find(*it + t) != s.end()) {
						isValid = true;
						break;
					}
				}

				// if t + any element in s is in s, player i is out
				// else insert t into s
				if (isValid) s.insert(t);
				else {
					cout << "Round #" << j + 1 << ": " << i+1 << " is out." << endl;
					out.insert(i);
				}
			}
		}
	}

	if (out.size() == (size_t)n) cout << "No winner." << endl;
	else {
		cout << "Winner(s):";
		for (int i = 0; i < n; i++) {
			if (out.find(i) == out.end()) {
				cout << " " << i+1;
			}
		}
		cout << endl;
	}

	return 0;
}