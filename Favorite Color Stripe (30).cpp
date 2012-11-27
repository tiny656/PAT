#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int e[500],t[10005];
int dp[2][10005];

int main()
{
    int n,m,l,i,j;
    while(cin >> n)
    {
        cin >> m;
        for(i = 1; i <= m; i++)
        {
            cin >> e[i];
        }
        cin >> l;
        for(i = 1; i <= l; i++)
        {
            cin >> t[i];
        }

        for(i = 0; i <= 1; i++)
        for(j = 0; j <= m; j++)
            dp[i][j] = 0;

        for(i = 1; i <= l; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(t[i] == e[j])
                {
                    dp[1][j] = max(dp[0][j]+1, dp[1][j-1]);
                }
                else
                {
                    dp[1][j] = max(dp[0][j], dp[1][j-1]);
                }
            }
            for(j = 1; j <= m; j++)
            {
                dp[0][j] = dp[1][j];
            }
        }
        cout << dp[0][m] << endl;

    }
    return 0;
}
