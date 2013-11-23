#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

struct edge
{
	int to;
	int dis;
	edge(int t, int d):to(t), dis(d){};
};
const int maxn = 501;
vector<edge> Adj[maxn];
int dist[maxn];
int team[maxn];
int tm[maxn];
bool used[maxn];
int pre[maxn];
int edgeNum[maxn];
int n, k, s, t, a, b ,w;

//Dijsktra Algorithm
void solve(int s, int t)
{
	//init
	fill(dist, dist + n, 0x3fffffff);
	fill(team, team + n, 0x3fffffff);
	fill(edgeNum, edgeNum + n, 0x3fffffff);
	dist[s] = 0;
	team[s] = tm[s];
	edgeNum[s] = 1;
	pre[s] = -1;
	fill(used, used + n, false);

	while (true)
	{
		int v = -1;
		for (int i = 0; i < n; i++)
		{
			if (!used[i] && (v == -1 || dist[i] < dist[v]))	v = i;
		}
		if (v == -1)	break;
		used[v] = true;
	
		for (int i = 0; i < Adj[v].size(); i++)
		{
			if (dist[ Adj[v][i].to ] > dist[v] + Adj[v][i].dis)
			{
				edgeNum[ Adj[v][i].to ] = edgeNum[v];
				dist[ Adj[v][i].to ] = dist[v] + Adj[v][i].dis;
				team[ Adj[v][i].to ] = team[v] + tm[Adj[v][i].to];
				pre[Adj[v][i].to] = v;
			}
			else if (dist[ Adj[v][i].to ] == dist[v] + Adj[v][i].dis)
			{
				edgeNum[ Adj[v][i].to ] += edgeNum[v];
				if (team[ Adj[v][i].to ] < team[v] + tm[Adj[v][i].to])
				{
					team[ Adj[v][i].to ] = team[v] + tm[Adj[v][i].to];
					pre[Adj[v][i].to] = v;
				}
			}
		}
	}
	printf("%d %d\n", edgeNum[t], team[t]); 
	stack<int> path;
	int tmp = t;
	
	while (tmp != -1)
	{
		path.push(tmp);
		tmp = pre[tmp];
	}
	printf("%d", path.top());
	path.pop();
	while (!path.empty())
	{
		printf(" %d", path.top());
		path.pop();
	}
	printf("\n");
}

int main()
{
	scanf("%d %d %d %d", &n, &k, &s, &t);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tm[i]);
	}
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		Adj[a].push_back(edge(b, w));
		Adj[b].push_back(edge(a, w));
	}
	solve(s, t);
	return 0;
}