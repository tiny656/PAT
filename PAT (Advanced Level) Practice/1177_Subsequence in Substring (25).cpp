#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	string s, p; 
	cin >> s >> p;

	pair<int, string> ans{10e5+10, ""};
	// brute force match p in s and find the shortest substring
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != p[0]) continue;
		int l = i, r = l+1;
		int k = 1;
		for (; r < s.size() && k != p.size(); r++) {
			if (s[r] == p[k]) k++;
			if (k == p.size()) break;
		}

		int len = r-l+1;
		if (k == p.size() && len < ans.first) {
			ans.first = len;
			ans.second = s.substr(l, len);
		}
	}

	cout << ans.second << endl;
	return 0;
}