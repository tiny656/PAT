#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/*
dp[i][j] 表示前i个字母，删去j个字符的结果,在第j位的状态转移是s[j]是否需要删除
dp[i][0] = 1
dp[i][1] = dp[i-1][0] + dp[i-1][1], 如果s[i]==s[i-1],比如abb,会多一次重复计算
dp[i][2] = dp[i-1][2] + dp[i-1][1], 分三种情况abcdee, abcede, abcde, 
前两种会有重复计算分别是(dp[i-2][1], a|b|c|d e), (1, ed de)
*/
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