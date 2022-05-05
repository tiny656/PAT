#include <iostream>
#include <cstring>
using namespace std;

// reference: ZJU ADS Presentation - Beautiful Subsequence - Group 4(https://www.bilibili.com/video/av668431512/)

// implementation for below code use reverse thought.
// define BIT A and B, 
// array A stores occurrence number of e[i], it will be incremental updated based on array e iteration.
// array B stores the ugly set (set size >= 2) result of e[i], it will be incremental updated based on array e iteration as well.
// if we want to know B[e[k]], how the relation transfer here?
// 1. every single number e[i] except range [ e[k]-m, e[k]+m ] will contribute to generate 2 element set.
// 2. every number e[i] except range [ e[k]-m, e[k]+m ] if its B already has ugly set, so it will contribute to e[k] as last element in the set.

// for example:
// 5 3 8 6
// 0: e[0] -> 5
// A 1 0 0 0
// B 0 0 0 0
// 1: e[1] -> 3
// A 1 1 0 0
// B 0 0 0 0
// 2: e[2] -> 8
// A 1 1 1           0
// B 0 0 1(5)+1(3)=2 0
// (5, 8), (3, 8)
// 3: e[3] -> 6
// A 1 1 1 1
// B 0 0 2 1(3)=1
// (3, 6)
// so sum of B is totale numebr of the ugly set (size > 2), then add extra empty set(1) and single element set(4), so result is 3 + 1 + 4 = 8.
// all combination for sample is 2^4 = 16, beautiful set = full set - ugly set = 16 - 8 = 8.

typedef long long int64;
const int64 maxn(101001), mod(1000000007);
int64 e[maxn], A[maxn+1], B[maxn+1];

int64 lowbit(int64 x) { return x & -x; }

void add(int64 arr[], int64 x, int64 c)
{
    for (int64 i = x; i <= maxn; i += lowbit(i))
        arr[i] = (arr[i] + c) % mod;
}

int64 sum(int64 arr[], int64 x)
{
    int64 res = 0;
    for (int64 i = x; i > 0; i -= lowbit(i))
        res = (res + arr[i]) % mod;
    return res;
}

// sum of (begin, end]
int64 query(int64 arr[], int64 begin, int64 end) {
    return (sum(arr, end) - sum(arr, begin)) % mod;
}

//快速幂 a^n % p
int64 pow(int64 a, int64 n, int64 p) {
    int64 ans = 1;
    while(n > 0)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int64 n, m;
    cin >> n >> m;
    for (int64 i = 0; i < n; i++) cin >> e[i];

    // 1. single elements not include
    // 2. empty set not include
    int64 ugly_sum = n + 1;

    add(A, e[0], 1);
    for (int64 i = 1; i < n; i++) {
        int64 t = e[i];
        int64 part1 = (sum(A, t-m-1) + query(A, t+m, maxn)) % mod;
        int64 part2 = (sum(B, t-m-1) + query(B, t+m, maxn)) % mod;

        add(A, t, 1);
        add(B, t, (part1+part2) % mod);
    }

    ugly_sum = (ugly_sum + sum(B, maxn)) % mod;

    int64 tot = pow(2, n, mod);
    cout << (tot + mod - ugly_sum) % mod << endl;
    return 0;
}

/*
ans: 8
4 2
5 3 8 6

ans: 57
6 1
1 1 1 1 1 1

ans: 73741786
30 30
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

ans: 16
6 1
10 12 14 16 1 2

ans: 20
6 1 
8 1 2 10 3 12

ans: 0
4 1
1 3 5 7
*/