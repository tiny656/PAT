#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Maximal Clique Problem

const int maxn = 1001;
int totFruitCount, maxFruitCount, minFruitPrice, cnt[maxn], clique[maxn], vis[maxn], GIds[maxn];
vector<int> fruitIds;
bool G[maxn][maxn];
unordered_map<int, int> fruitPrice;

bool dfs(int u, int count, int price) {
    int i, j;
    for (int i = u + 1; i <= totFruitCount; i++) {
        if (cnt[i] + count < maxFruitCount || (cnt[i] + count == maxFruitCount && price >= minFruitPrice)) return false;
        if (!G[u][i]) {
            for (j = 0; j < count; j++) if (G[i][vis[j]]) break;
            if (j == count) { 
                vis[count] = i;
                if (dfs(i, count + 1, price + fruitPrice[i])) return false;
            }
        }
    }
    if (count > maxFruitCount || (count == maxFruitCount && price < minFruitPrice)) {
        for (i = 0; i < count; i++) clique[i] = fruitIds[vis[i]];
        maxFruitCount = count;
        minFruitPrice = price;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> totFruitCount;
    fruitIds.resize(totFruitCount);

    // build safe fruit graph
    int fruit, price;
    vector<pair<int, int>> fruitPairs(n);
    for (int i = 0; i < n; i++) {
        cin >> fruitPairs[i].first >> fruitPairs[i].second;
    }

    int index = 1;
    for (int i = 1; i <= totFruitCount; i++) {
        cin >> fruit >> price;
        if (!GIds[fruit]) {
            GIds[fruit] = index;
            fruitIds[index++] = fruit;
        }
        fruitPrice[GIds[fruit]] = price;
    }

    for (auto &v : fruitPairs) {
        G[GIds[v.first]][GIds[v.second]] = G[GIds[v.second]][GIds[v.first]] = true;
    }

    minFruitPrice = 0x7fffffff;
    maxFruitCount = -1;

    for (int i = totFruitCount; i > 0; i--)
    {
        vis[0] = i;
        dfs(i, 1, fruitPrice[i]);
        cnt[i] = maxFruitCount;
    }

    cout << maxFruitCount << endl;
    sort(clique, clique+maxFruitCount);
    cout << setfill('0') << setw(3) << clique[0];
    for (int i = 1; i < maxFruitCount; i++) cout << " " << setfill('0') << setw(3) << clique[i];
    cout << endl;
    cout << minFruitPrice << endl;

    return 0;
}