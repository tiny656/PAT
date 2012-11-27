#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n,i;
    int e[10005];
    while(scanf("%d", &n) == 1 && n)
    {
        for(i = 1; i <= n; i++)
        {
            scanf("%d",&e[i]);
        }
        int ans = e[1], tmp = e[1];
        int s = e[1], t = e[1],index = 1;
        for(i = 2; i <= n; i++)
        {
            if(tmp > 0)
            {
                tmp = tmp + e[i];
                if(tmp > ans)
                {
                    ans = tmp;
                    index = i;
                }
            }
            else
            {
                tmp = e[i];
                if(tmp > ans)
                {
                    ans = tmp;
                    index = i;
                }
            }
        }
        t = e[index];
        tmp = ans;
        for(i = index; i >= 1; i--)
        {
            tmp -= e[i];
            if(!tmp)   break;
        }
        s = e[i];
        if(ans < 0 && s < 0 && t < 0)
        {
            printf("0 %d %d\n",e[1], e[n]);
        }
        else
        {
            printf("%d %d %d\n",ans,s,t);
        }
    }
    return 0;
}
