#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


class Clique {
public:
	Clique(int nv, int ne) {
		this->vertexNum = nv;
		this->edgeNum = ne;
		G.resize(nv + 1);
		for (int i = 1; i <= nv; i++) {
			G[i].resize(nv + 1);
			for (int j = 1; j <= nv; j++)
				G[i][j] = i == j;
		}
	}

	void addEdge(int p, int q) {
		G[p][q] = G[q][p] = true;
	}

	bool isClique(const vector<int> &sub) {
		for (int i = 0; i < sub.size(); i++) {
			for (int j = 0; j < sub.size(); j++) {
				if (!G[sub[i]][sub[j]]) return false;
			}
		}
		return true;
	}

	bool isMaximalClique(const vector<int> &sub) {
		vector<bool> remains(this->vertexNum + 1, true);
		for (const auto &e : sub) remains[e] = false;
		for (int i = 1; i < remains.size(); i++) {
			if (!remains[i]) continue;
			int cnt = 0;
			for (const auto &e : sub) cnt += G[i][e] ? 1 : 0;
			if (cnt == sub.size()) return false;
		}
		return true;
	}


private:
	int vertexNum, edgeNum;
	vector<vector<bool>> G; // graph matrix
};

int main() {
	int nv, ne, p, q;
	cin >> nv >> ne;
	Clique c(nv, ne);
	for (int i = 0; i < ne; i++) {
		cin >> p >> q;
		c.addEdge(p, q);
	}
	
	int k, n;
	vector<int> sub;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		sub.resize(n);
		for (int j = 0; j < n; j++) cin >> sub[j];

		if (!c.isClique(sub)) cout << "Not a Clique" << endl;
		else if (!c.isMaximalClique(sub)) cout << "Not Maximal" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}