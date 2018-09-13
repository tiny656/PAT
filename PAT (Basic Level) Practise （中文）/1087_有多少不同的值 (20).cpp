#include <bits/stdc++.h>
using namespace std;

const int len = 10000 / 2 * 3;
bool isVis[len];

int main() {
	int n, count = 0, v;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		v = i / 2 + i / 3 + i / 5;
		count += isVis[v] ? 0 : 1;
		isVis[v] = true;
	}
	cout << count << endl;
	return 0;
}