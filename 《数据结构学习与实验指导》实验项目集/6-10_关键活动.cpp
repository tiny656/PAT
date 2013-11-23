#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <map>
#include <cstring>
#include <stack>
using namespace std;

int mat[105][105];
int ve[105];
int vl[105];
int vis[105];
int n;
vector<int> adj[105];
/*
AOE关键活动
*/
bool topo(stack<int> &s)
{
	int in[105];
	fill(in, in+n+1, 0);
	fill(ve, ve+n+1, 0);
	fill(vis, vis+n+1, 0);
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (mat[j][i] != -1)
			{
				in[i]++;
			}
		}
	}
	int limit = n;
	while (limit--)
	{
		int find = 0, cur;
		for (cur = 1; cur <= n; cur++)
		{
			if (!in[cur] && !vis[cur])	
			{
				find = 1;
				break;
			}
		}
		if (!find)	return false;
		vis[cur] = 1;
		s.push(cur);
		for (int i = 1; i <= n; i++)
		{
			if (mat[cur][i] != -1)
			{
				--in[i];
				if (ve[cur] + mat[cur][i] > ve[i])
					ve[i] = ve[cur] + mat[cur][i];
			}
		}
	}
	return true;
}

bool critical_path()
{
	stack<int> s;
	if (!topo(s))	return false;
	//注意ve[]的最大值作为vl[]的初始化值
	int time = 0;
	for (int i = 1; i <= n; i++)
	{
		time = max(time, ve[i]);
	}
	fill(vl, vl+n+1, time);

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		for (int i = 1; i <= n; i++	)
		{
			if (mat[i][cur] != -1)
			{
				if (vl[cur] - mat[i][cur] < vl[i])
					vl[i] = vl[cur] - mat[i][cur];
			}
		}
	}
	map<int, int> hash;
	printf("%d\n", time);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (mat[i][j] != -1)
			{
				int ee = ve[i];
				int el = vl[j]-mat[i][j];
				if (ee == el)
				{
					hash[i*1000+j] = 1;
				}	
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = adj[i].size()-1; j >= 0; j--)
		{
			if (hash[i*1000+adj[i][j]])
			{
				printf("%d->%d\n", i, adj[i][j]);
			}
		}
	}
	return true;
}


int main()
{
	int m, a, b, w;
	scanf("%d %d", &n, &m);
	//init
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			mat[i][j] = -1;
		}
	}
	for (int i = 0 ; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		adj[a].push_back(b);
		mat[a][b] = w;
	}
	if (!critical_path())
	{
		printf("0\n");
	}

	return 0;
}