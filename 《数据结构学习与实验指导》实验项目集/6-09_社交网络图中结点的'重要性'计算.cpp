#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

/*
Spfa算法 
*/ 

const int MAX = 0x3fffffff;
int dis[10005];
bool visited[10005];

vector<int> adj[10005];
int n;
void Spfa(int start)
{
    int i;
    for (i = 0; i <= n; ++i)//初始化
    {
        dis[i] = MAX;
        visited[i] = false;    
    }
    queue<int> Q;
    dis[start] = 0;
    visited[start] = true;
    Q.push(start);
    while (!Q.empty())
    {
        int temp = Q.front();
        Q.pop();
        for (i = 0; i < adj[temp].size(); ++i)
        {
            if (dis[temp] + 1 < dis[adj[temp][i]])
            {
                dis[adj[temp][i]] = dis[temp] + 1;
                if (!visited[adj[temp][i]])
                {
                    Q.push(adj[temp][i]);
                    visited[adj[temp][i]] = true;    
                }        
            }            
        }
        visited[temp] = false;            
    }
    int ok = 1;    
    double cnt = 0.0;
    for(i = 1; i <= n; i++)
    {
        if(dis[i] == MAX)   
        {
            ok = 0;
            break;
        } 
        else
        {
            cnt += dis[i];
        }
   }
   printf("Cc(%d)=", start);
   if(!ok)  printf("0.00\n");
   else printf("%.2lf\n", (double)(n-1)/cnt);
}

int main()
{
    int m,i,a,b,ask;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= m; i++)
    {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &ask);
    for(i = 1; i <= ask; i++)
    {
        scanf("%d", &a);
        Spfa(a);
    }
    return 0;
}