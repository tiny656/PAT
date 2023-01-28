#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 10001;


bool IsPrime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	int mark[MAXN], ans[MAXN];
	fill(mark, mark+MAXN, 0);
	for (int i = a; i <= b; i++) {
		if (mark[i] > 0) continue;

		vector<int> numbers;
		int seed = i;
		bool vis[MAXN];
		fill(vis, vis+MAXN, false);

		while (true) {
			// 环
			if (vis[seed]) {
				for (int j = 0; j < numbers.size(); j++) 
					mark[numbers[j]] = 2;
				break;
			}

			if (seed == 1) {
				// 依附
				for (int j = 0; j < numbers.size(); j++)
					mark[numbers[j]]++;
				ans[i] = numbers.size() * (IsPrime(i) ? 2 : 1);
				break;
			};

			vis[seed] = true;
			numbers.push_back(seed);

			int res = 0;
			while (seed) {
				int digit = seed % 10;
				res += digit * digit;
				seed /= 10;
			}
			seed = res;
		}
	}

	bool isOk = false;
	for (int i = a; i <= b; i++) {
		if (mark[i] == 1) {
			isOk = true;
			cout << i << " " << ans[i] << endl;
		}
	}
	if (!isOk) cout << "SAD" << endl;

	return 0;
}