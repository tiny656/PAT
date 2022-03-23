#include <iostream>
#include <vector>
using namespace std;

/*
Solution 1:
dp[i,j] i个选j组最后得到的结果
dp[i,j] = products of belows
            dp[i-1, j-1]*(dp[i, 1] - dp[i-1, 1])^(C[i-2, j-2])
            dp[i-2, j-1]*(dp[i, 1] - dp[i-2, 1])^(C[i-3, j-2])
            ......
            dp[j-1, j-1]*(dp[i, 1] - dp[j-1, 1])^(C[j-2, j-2])
递推O(n), 二维O(n^2), 复杂度O(n^3)

Soution 2:
......[X]...... 计算当前X的组对于最后分成m组后乘积的贡献次数,
如果x是sum(i,...,j), 则计算次数y
1. m == 1 && i == 1 && j == n => y = 1
2. i == 1 && m-2 >= 0 && n-j-1 >= m-2 => y = c[n-j-1, m-2]
3. j == n && m-2 >= 0 && i-2 >= m-2 => y = c[i-2, m-2]
4. i != 1 && j != n && m-3 >= 0 && i-2+n-j-1 >= m-3 => y = c[i-2+n-j-1, m-3] i-2+n-j-1表示X两边可以分组的位置，如果他们分成m-1组(X占了一组), 则需要在这些可能位置插入m-3个隔板。

Extra: 
(a+b) % p = (a%p + b%p) % p
a^b % p = (a%p)^b % p
if p is prime, a^b % p = a^(b % phi(p) + phi(p)) % p = a^(b % (p-1)) % p
*/

typedef unsigned long long int64;
const int64 maxn(1005), mod(1000000007);
int64 c[maxn][maxn];
vector<int64> a, sum;

//快速幂 a^n % p
int64 pow(int64 a, int64 n, int64 p)    
{
    int64 ans = 1;
    while(n > 0)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

//计算C(m, n)
void calcC(int m, int n, int64 p)
{
    for (int i = 0; i <= m; i++)
    for (int j = 0; j <= min(i, n); j++) {
        if (j == 0|| i == j) c[i][j] = 1;
        else c[i][j] = ((c[i-1][j-1] % p) + (c[i-1][j] % p)) % p;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    a.resize(n+1);
    sum.resize(n+1);
    a[0] = sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = (sum[i-1] + a[i]) % mod;
    }

    calcC(n, m, mod-1);

    int64 result = 1;
    for (int i = 1; i <= n; i++) 
    for (int j = i; j <= n; j++) {
        int64 x = (sum[j] - sum[i-1] + mod) % mod;
        int64 y = 0;
        // cout << "1:   " << i << " " << j << " " << m-2 << endl;
        // cout << "2:   " << n-j << " " << i-1 << endl;
        if (m == 1 && i == 1 && j == n) y = 1;
        else if (i == 1 && m-2 >= 0 && n-j-1 >= m-2) y = c[n-j-1][m-2];
        else if (j == n && m-2 >= 0 && i-2 >= m-2) y = c[i-2][m-2];
        else if (i != 1 && j != n && m-3 >= 0 && i-2+n-j-1 >= m-3) y = c[i-2+n-j-1][m-3];
        // cout << "3:   " << x  << " " << y << endl << endl;
        result *= pow(x, y, mod);
        result %= mod;
    }

    cout << result << endl;

    return 0;
}