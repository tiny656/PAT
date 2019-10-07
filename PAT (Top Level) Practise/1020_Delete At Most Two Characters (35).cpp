#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef long long int64;

int64 dp[1000005][3];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) dp[i][1] = (s[i] == s[i-1] ? 0 : 1) + dp[i-1][1];
    dp[1][2] = 1;
    for (int i = 2; i < n; i++) {
        int64 t = dp[i-1][2] + dp[i-1][1];
        if (s[i] == s[i-1]) dp[i][2] = t - dp[i-2][1]; // abcdee
        else if (s[i] == s[i-2]) dp[i][2] = t - 1; // abcede
        else dp[i][2] = t; // abcde
    }
    cout << dp[n-1][0] + dp[n-1][1] + dp[n-1][2] << endl;
    return 0;
}