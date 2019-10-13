#include <cstdio>
#include <cstring>
#include <unordered_map>
using namespace std;

/*
dp[i][j], 前i个字符保留j个的结果，状态转移为是否保留当前s[i]
dp[i][j] = dp[i-1][j](不保留) + dp[i-1][j-1](保留), 但是如果s[i]之前出现过，会有重复的统计
所以需要减去dp[ pos[s[i]] - 1][j-1], pos[s[i]]记录s[i]上一次出现的位置
*/

typedef long long int64;
const int maxn = 1005;
const int64 M = 1000000007LL;
char s[maxn];
int64 dp[maxn][101];

int main() {
    scanf("%s", s+1);
    int n = strlen(s+1);
    int limit = n <= 100 ? n : 100;
    unordered_map<char, int> pos;
    dp[0][0] = 1LL;
    for (int i = 1; i <= n; i++) dp[i][0] = 1LL;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= limit; j++) {
            int64 repeat = pos[s[i]] == 0 ? 0 : dp[pos[s[i]]-1][j-1];
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] - repeat) % M;
        }
        pos[s[i]] = i;
    }

    int64 ans = 0LL;
    for (int i = 1; i <= limit; i++) ans = (ans + dp[n][i]) % M;
    printf("%lld", ans);

    return 0;
}