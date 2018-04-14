#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// basic topological implement
// maintain in degree value, check in degree is 0 for vertex in order
class DirectedGraph {
public:
	DirectedGraph(int n, int m) {
		this->vertexNum = n;
		this->edgeNum = m;
		this->G.resize(n + 1);
		this->inDegree.resize(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			this->G[i].resize(n+1, false);
			this->G[i][i] = true;
		}
	}

	void addEdge(int p, int q) {
		this->G[p][q] = true;
		this->inDegree[q] += 1;
	}

	bool isTopologicalOrder(const vector<int> &order) {
		vector<int> tempInDegree(this->inDegree);
		for (const auto &e : order) {
			if (tempInDegree[e] != 0) return false;
			for (int i = 1; i <= this->vertexNum; i++) {
				if (e != i && this->G[e][i])
					tempInDegree[i]--;
			}
		}
		return true;
	}


private:
	int vertexNum, edgeNum;
	vector<vector<bool>> G;
	vector<int> inDegree;
};

int main() {
	int n, m, k, p, q;
	cin >> n >> m;
	DirectedGraph dg(n, m);
	for (int i = 0; i < m; i++) {
		cin >> p >> q;
		dg.addEdge(p, q);
	}

	cin >> k;
	vector<int> order(n);
	int firstPrint = true;
	for (int i = 0; i < k; i++) {

		for (int j = 0; j < n; j++) {
			cin >> order[j];
		}

		if (!dg.isTopologicalOrder(order)) {
			if (firstPrint) firstPrint = false;
			else cout << " ";
			cout << i;
		}
	}
	cout << endl;
	return 0;
}

