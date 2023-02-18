#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 14.478 Replacement Selection
// https://www.youtube.com/watch?v=m0v-trXc2yI

void PrintArray(const vector<int> &arr) {
	cout << arr[0];
	for (size_t i = 1; i < arr.size(); i++) {
		cout << " " << arr[i];
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> backup, run, arr(n);
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int index = 0, tot = 0;
	for (; index < m; index++) q.push(arr[index]);

	// at least pop n elements
	while (tot < n) {
		run.push_back(q.top());
		q.pop();
		tot++;

		// if there are still elements in arr
		// use run.back() to compare with arr[index
		// if arr[index] > run.back(), push it into q
		// else push it into backup
		if (index < n) {
			if (arr[index] > run.back()) q.push(arr[index]);
			else backup.push_back(arr[index]);
			index++;
		}

		// if q is empty, print current run and push backup into q
		if (q.empty()) {
			if (!run.empty()) PrintArray(run);
			run.clear();
			for (auto &e : backup) q.push(e);
			backup.clear();
		}
	}

	return 0;
}