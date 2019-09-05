#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct e
{
    int s,t,w;
}Edge[50*99+100];

int cmp(const e &a, const e &b)
{
    return a.w < b.w;
}

int p[105];
int Rank[105];

void MakeSet(int x)
{
    p[x] = x;
    Rank[x] = 0;
}

int FindSet(int x)
{
    if(x != p[x]) p[x] = FindSet(p[x]);
    return p[x];
}

void Union(int x, int y)
{
    int fx,fy;
    fx = FindSet(x);
    fy = FindSet(y);
    if(Rank[fx] < Rank[fy])
    {
        p[fx] = fy;
    }
    else
    {
        p[fy] = fx;
        if(Rank[fx] == Rank[fy])
        {
            Rank[fx] += 1;
        }
    }
}

vector<int> adj[105];

int main()
{
    int i,elen,n;
    while(scanf("%d", &n) == 1 && n)
    {
        int elen = n*(n-1)/2;

        for(i = 0; i <= n; i++)
        {
            adj[i].clear();
            MakeSet(i);
        }

        int tmps,tmpt,tmpw,ok,len = 0;
        for(i = 0; i < elen; i++)
        {
            scanf("%d %d %d %d",&tmps,&tmpt,&tmpw,&ok);
            if(ok)
            {
                Union(tmps, tmpt);
            }
            else
            {
                Edge[len].s = tmps;
                Edge[len].t = tmpt;
                Edge[len].w = tmpw;
                len++;
            }
        }
        int ans = 0;

        //KruskalËã·¨ ÇóMST

        sort(Edge, Edge+len, cmp);

        for(i = 0; i < len; i++)
        {
            if(FindSet(Edge[i].s) != FindSet(Edge[i].t))
            {
                ans += Edge[i].w;
                Union(Edge[i].s, Edge[i].t);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
