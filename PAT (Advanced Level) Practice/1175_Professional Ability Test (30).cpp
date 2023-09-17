#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 1. use topology algorithm to check if graph is a DAG.
// 2. construct a convergence start point to link all points which in degree is 0.
// 3. call dijsktra algo to find all short distance from convergence start point.

const int MAXN = 0x3fffffff;

class Node {
public:
	int t, s, d;
};

vector<vector<Node>> G;
vector<int> pre;
vector<bool> hasInDegree;

bool isDAG() {
	vector<int> inDegree(G.size(), 0);
	for (int i = 0; i < G.size(); i++) {
		for (int j = 0; j < G[i].size(); j++) {
			inDegree[G[i][j].t]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < G.size(); i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	int cnt = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < G[u].size(); i++) {
			int v = G[u][i].t;
			inDegree[v]--;
			if (inDegree[v] == 0) q.push(v);
		}
	}

	return cnt == G.size();
}

void dijkstra() {
	int src = G.size() - 1; // G[n] is convergence start point
	vector<int> dis(G.size(), MAXN), vou(G.size(), 0);
	vector<bool> visited(G.size(), false);
	pre.resize(G.size(), -1);
	dis[src] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, src});
	while (!pq.empty()) {
		auto e = pq.top(); pq.pop();
		int s = e.first, u = e.second;
		visited[u] = true;

		if (dis[u] != MAXN && dis[u] < s) continue;

		for (int i = 0; i < G[u].size(); i++) {
			Node v = G[u][i];
			if (visited[v.t]) continue;
			if (dis[u] + v.s < dis[v.t]) {
				dis[v.t] = dis[u] + v.s;
				vou[v.t] = vou[u] + v.d;
				pre[v.t] = u;
				pq.push({dis[v.t], v.t});
			} else if (dis[u] + v.s == dis[v.t] && vou[u] + v.d > vou[v.t]) {
				vou[v.t] = vou[u] + v.d;
				pre[v.t] = u;
				pq.push({dis[v.t], v.t});
			}
		}
	}
}

void print(int t) {
	int src = G.size() - 1; // G[n] is convergence start point
	if (t == src) return;
	print(pre[t]);
	if (hasInDegree[t]) cout << "->";
	cout << t;
}


int main() {
	ios::sync_with_stdio(false);
	int n, m, t;
	cin >> n >> m;
	G.resize(n, vector<Node>());
	hasInDegree.resize(n+1, false);
	for (int i = 0; i < m; i++) {
		Node node = Node();
		cin >> t >> node.t >> node.s >> node.d;
		hasInDegree[node.t] = true;
		G[t].push_back(node);
	}

	vector<int> starts;
	for (int i = 0; i < n; i++) {
		if (!hasInDegree[i]) starts.push_back(i);
	}

	bool isValid = isDAG();
	cout << (isValid ? "Okay." : "Impossible.") << endl;

	// add a convergence point G[n] to link all starts
	G.push_back(vector<Node>());
	for (const int &t : starts) {
		Node node = Node();
		node.t = t;
		node.s = node.d = 0;
		G[n].push_back(node);
	}
	dijkstra();

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> t;
		if (!hasInDegree[t]) cout << "You may take test " << t << " directly." << endl;
		else if (!isValid) cout << "Error." << endl;
		else { print(t); cout << endl;}
	}

	return 0;
}