#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

double a[1001],b[1001];
int main()
{
    int i;
    for (i=0;i<=1000;i++) a[i]=b[i]=0;
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
        a[i] += b[i];
        if(a[i])    ans++;
    }
    cout << ans;
    for(i = 1000; i >= 0; i--)
    {
        if(a[i])    printf(" %d %.1lf", i, a[i]);
    }
    return 0;
}
