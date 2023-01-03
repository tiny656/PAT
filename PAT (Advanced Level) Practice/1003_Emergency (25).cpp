#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define N 505

int n,m,s,e;
int team[N];
int numDis,minDis,maxTeam;
int vis[N];
int matrix[N][N];

vector<int> path;

void DFS(int next)//深搜 + 回溯
{
    int i;
    if(next == e)//如果当前点是目标点
    {
        int curTeam = 0, curDis = 0;
        for(i = 0; i < path.size(); i++)
        {
            curTeam += team[path[i]];
        }
        for(i = 0; i < path.size()-1; i++)
        {
            curDis += matrix[path[i]][path[i+1]];
        }

        if(curDis < minDis)
        {
            numDis = 1;
            minDis = curDis;
            maxTeam = curTeam;
        }
        else if(curDis == minDis)
        {
            numDis++;
            if(curTeam > maxTeam)   maxTeam = curTeam;
        }
        return;
    }
    for(i = 0; i < n; i++)
    {
        if(matrix[next][i] != -1)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                path.push_back(i);
                DFS(i);
                path.pop_back();
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    int i,a,b,d,j;
    while(cin >> n >> m >> s >> e)
    {

        for(i = 0; i < n; i++,matrix[i][i] = 0,vis[i] = 0)
        {
            for(j = 0; j < n; j++)
            {
                matrix[i][j] = -1;
            }
        }

        for(i = 0; i < n; i++)
        {
            cin >> team[i];
        }
        for(i = 0; i < m; i++)
        {
            cin >> a >> b >> d;
            matrix[a][b] = matrix[b][a] = d;
        }

        path.clear();
        numDis = 0;
        minDis = 0x7fffffff;
        maxTeam = -1;

        //搜索+回溯开始
        vis[s] = 1;
        path.push_back(s);
        DFS(s);
        path.pop_back();
        vis[s] = 0;

        //打印答案
        cout << numDis << " " << maxTeam << endl;
    }
    return 0;
}
