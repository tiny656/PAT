#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, v;
	cin >> n;
	vector<int> diffVec(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v;
		++diffVec[abs(i + 1 - v)];
	}
	for (int i = diffVec.size() - 1; i >= 0; i--) {
		if (diffVec[i] > 1) cout << i << " " << diffVec[i] << endl;
	}
	return 0;
}