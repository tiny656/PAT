#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

double a[1001],b[1001],c[2002];
int main()
{
    int i,j;
    for (i=0;i<=1000;i++) a[i]=b[i]=c[i]=0;
    int n,k;
    double v;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> k >> v;
        a[k] = v;
    }
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> k >> v;
        b[k] = v;
    }
    int ans = 0;
    for(i = 0; i <= 1000; i++)
    {
        for(j = 0; j <= 1000; j++)
        {
            c[i+j] += a[i]*b[j];
        }
    }
    for(i = 0; i <= 2000; i++)
    {
        if(c[i])    ans++;
    }
    cout << ans;
    for(i = 2000; i >= 0; i--)
    {
        if(c[i])    printf(" %d %.1lf", i, c[i]);
    }
    return 0;
}
