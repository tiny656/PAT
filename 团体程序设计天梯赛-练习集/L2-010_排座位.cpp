#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

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

    int Find(int p) {
        return p == fa[p] ? p : (fa[p] = Find(fa[p]));
    }

    void Union(int p, int q) {
        int i = Find(p), j = Find(q);
        if (i == j) return;
        this->num--;
        if (rank[i] < rank[j]) { fa[i] = j; rank[j] += 1;}
        else { fa[j] = i; rank[i] += 1; }
    }

    bool IsConnected(int p, int q) {
        return Find(p) == Find(q);
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m, k, g1, g2, r;
    cin >> n >> m >> k;
    UnionSet friends(n);
    vector<unordered_set<int>> friendSet(n+1), enemySet(n+1);
    for (int i = 0; i < m; i++) {
        cin >> g1 >> g2 >> r;
        if (r == 1)  {
            friends.Union(g1, g2);
            friendSet[g1].insert(g2);
        } else {
            enemySet[g1].insert(g2);
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> g1 >> g2;
        if (friendSet[g1].find(g2) != friendSet[g1].end() || friendSet[g2].find(g1) != friendSet[g2].end())
            cout << "No problem" << endl;
        else if (enemySet[g1].find(g2) == enemySet[g1].end() && enemySet[g2].find(g1) == enemySet[g2].end()) 
            cout << "OK" << endl;
        else if (friends.IsConnected(g1, g2)) cout << "OK but..." << endl;
        else cout << "No way" << endl;
    }

    return 0;
}