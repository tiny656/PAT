#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//  Minimum Spanning Tree, Kruskal + Greedy
// 1.  Sort the edges by power and weapon
// 2.  Greedily add the edges to the MST

class UnionSet {
public:
	int num;
	vector<int> fa, rank;

	UnionSet(int n) {
		this->num = n;
		this->rank.resize(n+1);
		this->fa.resize(n+1);
		for (int i = 0; i < n+1; i++) {
			rank[i] = 0;
			fa[i] = i;
		}
	}

	int find(int p) {
		if (p == fa[p]) return p;
		else fa[p] = find(fa[p]);
		return fa[p];
	}

	void union_set(int p, int q) {
		int i = find(p);
		int j = find(q);
		if (i == j) return;
		if (rank[i] < rank[j]) { fa[i] = j; rank[j] += 1;}
		else { fa[j] = i; rank[i] += 1; }
	}

	bool connected(int p, int q) {
		return find(p) == find(q);
	}

};

class Edge {
public:
	int p, q, power, weapon, index;
	Edge(int p, int q, int power, int weapon, int index) {
		this->p = p;
		this->q = q;
		this->power = power;
		this->weapon = weapon;
		this->index = index;
	}

	bool operator<(const Edge &e) const {
		if (e.power == this->power)
			return this->weapon > e.weapon;
		else return this->power < e.power; 
	}
	 
};


int main() {
	ios::sync_with_stdio(false);
	int n, m, p, q, power, weapon;
	cin >> n >> m;
	vector<Edge> edges;
	for (int i = 0; i < m; i++) {
		cin >> p >> q >> power >> weapon;
		edges.push_back(Edge(p, q, power, weapon, i+1));
	}

	sort(edges.begin(), edges.end());

	pair<int, int> result;
	vector<int> monsters;
	auto u = UnionSet(n);
	int edge_num = 0;
	for (size_t i = 0; i < edges.size() && edge_num < n; i++) {
		int p = edges[i].p;
		int q = edges[i].q;
		if (!u.connected(p, q)) {
			u.union_set(p, q);
			result.first += edges[i].power;
			result.second += edges[i].weapon;
			monsters.push_back(edges[i].index);
			edge_num++;
		}
	}

	sort(monsters.begin(), monsters.end());

	cout << result.first << " " << result.second << endl;
	cout << monsters[0];
	for (size_t i = 1; i < monsters.size(); i++) cout << " " << monsters[i];
	cout << endl;
	return 0;
}

