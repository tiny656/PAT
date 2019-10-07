#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<vector<int>> dist(n+1, vector<int>(n+1, 0x3fffffff));
    for (int i = 1; i <= n ; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        dist[a][b] = dist[b][a] = 1;
    }

    //  Floyd short path
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] <= 6) count++;
        }
        printf("%d: %.2f%%\n", i, count / (float)n * 100);
    }

    return 0;
}
