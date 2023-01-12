#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int index, vector<int> &tree) {
	if (index >= tree.size()) return;
	DFS(index << 1, tree);
	DFS(index << 1 | 1, tree);
	int node;
	cin >> node;
	tree[index] = node;
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> nodes(n+1);
	DFS(1, nodes);
	cout << nodes[1];
	for (int i = 2; i <= n; i++)
		cout << " " << nodes[i];
	cout << endl;
	return 0;
}