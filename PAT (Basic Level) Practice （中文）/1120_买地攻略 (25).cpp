#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;

// Solution 1: O(n^2), 遍历所有可能的区间并统计合法的区间数
int Solution1(const vector<int64> &sum, int64 n, int64 m) {
	int64 cnt = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (sum[j]-sum[i] <= m) cnt++;
		}
	}
	return cnt;
}

// Solution 2: O(nlogn), 二分查找, 从后往前遍历, 对于每个i, 二分查找第一个pos, 使得sum[pos] >= sum[i]-m
int Solution2(const vector<int64> &sum, int64 n, int64 m) {
	int64 cnt = 0;
	for (int i = n; i >= 1; i--) {
		int pos = lower_bound(sum.begin(), sum.end(), sum[i] - m) - sum.begin();
		cnt += i - pos;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	int64 n, m, v;
	cin >> n >> m;
	vector<int64> sum(n+1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> v;
		sum[i] = sum[i-1] + v;
	}
	// cout << Solution1(sum, n, m) << endl;
	cout << Solution2(sum, n, m) << endl;
	return 0;
}
