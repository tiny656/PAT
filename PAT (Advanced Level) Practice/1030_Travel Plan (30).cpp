#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
#include<cstdlib>
using namespace std;

const int maxn = 505;
int noteMoney[maxn];
int dist[maxn];
int path[maxn];

struct edge
{
    int to;
    int money;
    int len;
    bool operator < (const edge &a) const
    {
        if( a.len == len )
            return money > a.money;
        return len > a.len;
    }
}temp,cur;

vector<edge> AdjList[maxn];

/*BFS+Priority_Queue*/
void BFS(int s,int d)
{
    int i;
    priority_queue<edge> pq;
    temp.len = 0;
    temp.money = 0;
    temp.to = s;
    noteMoney[temp.to] = 0;
    dist[temp.to] = 0;
    pq.push(temp);
    path[s] = -1;
    //cout << "-1到" << s << endl;
    while( !pq.empty() )
    {
        temp = pq.top();
        if( temp.to == d )
        {
            stack<int> ans;
            int pp = temp.to;
            while(pp != -1)
            {
                ans.push(pp);
                pp = path[pp];
            }
            while(!ans.empty())
            {
                cout << ans.top() << " ";
                ans.pop();
            }
            cout << temp.len << " " << temp.money << endl;
            return;
        }
        pq.pop();
        for( i = 0 ; i < AdjList[temp.to].size() ; i++ )
        {
            cur = AdjList[temp.to][i];
            cur.money += temp.money;
            cur.len += temp.len;
            if(cur.len < dist[cur.to])
            {
                dist[cur.to] = cur.len;
                //cout << temp.to << "到" << cur.to << endl;
                noteMoney[cur.to] = cur.money;
                //cout << cur.to << "的花费更新成" << cur.money << endl;
                path[cur.to] = temp.to;
                pq.push(cur);
            }
            else if(cur.len == dist[cur.to] && noteMoney[cur.to] > cur.money)
            {
                //cout << temp.to << "到" << cur.to << endl;
                noteMoney[cur.to] = cur.money;
                //cout << cur.to << "的花费更新成" << cur.money << endl;
                path[cur.to] = temp.to;
                pq.push(cur);
            }
        }
    }
}
/*
5 6 0 3
0 4 1 20
0 1 2 10
0 2 1 30
4 3 1 20
1 3 1 20
2 3 1 20
*/
int main()
{
    int n,fee,r,i,s,d,l,t,start,end;
    scanf("%d %d %d %d",&n,&r,&start,&end);
    for( i = 1 ; i <= r ; i++ )
    {
        scanf("%d %d %d %d",&s,&d,&l,&t);
        temp.to = d;
        temp.len = l;
        temp.money = t;
        AdjList[s].push_back(temp);
        temp.to = s;
        temp.len = l;
        temp.money = t;
        AdjList[d].push_back(temp);
    }

    for(i = 0; i < n; i++)  {noteMoney[i] = 10000000;dist[i] = 10000000;}

    BFS(start,end);

    return 0;
}
