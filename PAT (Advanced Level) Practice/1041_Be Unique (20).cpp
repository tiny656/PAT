//cout 会超时
#include <cstdio>
#include <cstring>
using namespace std;

int e[100005];
int cnt[10001];

int main()
{
    int n,i,j;
    while(scanf("%d", &n) == 1)
    {
        memset(cnt,0,sizeof(cnt));
        for(i = 0; i < n; i++)
        {
            scanf("%d",&e[i]);
            cnt[e[i]]++;
        }
        int ok = 0;
        for(i = 0; i < n; i++)
        {
            if(cnt[e[i]] == 1)
            {
                ok = 1;
                printf("%d\n", e[i]);
                break;
            }
        }
        if(!ok) puts("None");
    }
    return 0;
}
