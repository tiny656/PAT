#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 105;
const int INF = 0x3fffffff;
int matrix[maxn][maxn];
int HengMax[maxn], ShuMin[maxn];

int main() {
    int n, m, a, b, sp;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) matrix[i][j] = INF;
        matrix[i][i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> sp;
        matrix[a][b] = matrix[b][a] = sp;
    }
    
    for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
        if(matrix[i][j] > matrix[i][k] + matrix[k][j]) {
            matrix[i][j] = 	matrix[i][k] + matrix[k][j];
        }
    }

    int idx = 0;
    int min = INF, max;
    for (int i = 1; i<=n; i++) {
        max = 0;
        for (int j = 1; j <= n; j++) {
            if (max < matrix[i][j]) max = matrix[i][j];
        }
        if (min > max) {
            min = max;
            idx = i;
        }
    }

    if (idx == 0) cout << "0" << endl;
    else cout << idx << " " << min << endl;

    return 0;
}