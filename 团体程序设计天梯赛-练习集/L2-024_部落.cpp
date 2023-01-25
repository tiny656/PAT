#include <iostream>
using namespace std;

const int MAXN = 1e4+1;

class UnionSet {
public:
	int num;
	int *fa, *rank;

	UnionSet(int n) {
		this->num = n;
		this->fa = new int[n+1];
		this->rank = new int[n+1];
		for (int i = 0; i < n+1; i++) {
			fa[i] = i;
			rank[i] = 0;
		}
	}

	int Find(int p) {
		return p == fa[p] ? p : (fa[p] = Find(fa[p]));
	}

	bool IsConnected(int p, int q) {
		return Find(p) == Find(q);
	}

	void Union(int p, int q) {
		int fp = Find(p), fq = Find(q);
		if (IsConnected(fp, fq)) return;
		if (rank[fp] < rank[fq]) fa[fp] = fq;
		else {
			fa[fq] = fp;
			if (rank[fp] == rank[fq]) rank[fp] += 1;
		}
		this->num--;
	}
};

int main() {
	ios::sync_with_stdio(false);
	UnionSet tribes(MAXN);
	int n, k, p, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k == 1) {
			cin >> p;
			cnt = max(p, cnt);
		} else {
			cin >> p;
			cnt = max(p, cnt);
			for (int j = 1; j < k; j++) {
				int q;
				cin >> q;
				cnt = max(q, cnt);
				tribes.Union(p, q);
			}
		}
	}

	cout << cnt << " " << (tribes.num + cnt - MAXN) << endl;

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int p, q;
		cin >> p >> q;
		cout << (tribes.IsConnected(p, q) ? "Y" : "N") << endl;
	}

	return 0;
}