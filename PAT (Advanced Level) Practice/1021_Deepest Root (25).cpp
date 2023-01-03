/*
    并查集判断 树的个数
    第1次BFS找到最远叶子结点
    第2次BFS找到距离最远的所有结点集合
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define N 10005
int p[N];
int rk[N];
int dist[N];
void MakeSet(int x)
{
    p[x] = x;
    rk[x] = 0;
}

int FindSet(int x)
{
    if(x != p[x])   return p[x] = FindSet(p[x]);
    return p[x];
}

void Union(int a,int b)
{
    int fa = FindSet(a);
    int fb = FindSet(b);
    if(rk[fa] < rk[fb])
    {
        p[fa] = fb;
    }
    else
    {
        p[fb] = fa;
        if(rk[fa] == rk[fb])
        {
            rk[fa] += 1;
        }
    }
}

vector<int> adj[N];

int bfs(int start)
{
    memset(dist,-1,sizeof(dist));

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farMax = 0, i;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(i = 0; i < adj[cur].size(); i++)
        {
            if(dist[ adj[cur][i] ] == -1)
            {
                dist[adj[cur][i]] = dist[cur] + 1;
                q.push(adj[cur][i]);
            }
        }
        if(dist[cur] > farMax) farMax = dist[cur];
    }
    return farMax;
}


int main()
{
    int n,i,all,a,b;
    cin >> n;
    all = n;
    for(i = 1; i <= n; i++)
    {
        MakeSet(i);
    }
    for(i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        if(FindSet(a) != FindSet(b))
        {
            all--;
            Union(a,b);
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(all != 1)
    {
        cout << "Error: " << all << " components" << endl;
    }
    else
    {
        set<int> ans;
        int farMax = bfs(1);//离1最远距离
        int tmp;
        for(i = 1; i <= n; i++)
        {
            if(dist[i] == farMax)
            {
                tmp = i;
                break;
            }
        }
        farMax = bfs(tmp);//寻找距离最远的两点
        ans.insert(tmp);//自身也要加入
        for(i = 1; i <= n; i++)
        {
            if(dist[i] == farMax)
                ans.insert(i);
        }
        for(set<int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
            cout << *iter << endl;
    }
    return 0;
}
