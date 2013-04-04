#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 1005
int matrix[N][N];
int tmp[N][N];
int vis[N];

int partNum;

void dfs(int x,int n)
{
    if(!vis[x])
    {
        //cout << x << endl;
        vis[x] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(tmp[x][i] && !vis[i])
            {
                dfs(i,n);
            }
        }
    }
}


void f(int x,int n)
{
    int i,j;
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == x || j == x)    tmp[i][j] = 0;
            else tmp[i][j] = matrix[i][j];
        }
    }

    partNum = 0;
    memset(vis,0,sizeof(vis));

    for(i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i,n);
            //cout << "ok" << endl;
            partNum++;
        }
    }
    cout << partNum-2 << endl;
}

int main()
{
    int n,m,k,i,j,a,b,c;
    while(cin >> n >> m >> k)
    {
        for(i = 1; i <= n; i++,matrix[i][i] = 1)
        for(j = 1; j <= n; j++)
        {
            matrix[i][j] = 0;
        }
        for(i = 0; i < m; i++)
        {
            cin >> a >> b;
            matrix[a][b] = matrix[b][a] = 1;
        }
        for(i = 1; i <= k; i++)
        {
            cin >> c;
            f(c,n);
        }

    }
    return 0;
}
