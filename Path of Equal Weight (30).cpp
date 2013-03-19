#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

int w[105];


map<int, vector<int> > root;
int n,m,s;
deque<int> path;
vector<vector<int> > Res;

void dfs(int ID,int curWeight)
{
	int i;
	if(curWeight == s)
	{
		if(!root[ID].empty())	return;
		vector<int> tmpVec;
		for(i = 0; i < path.size(); i++)
			tmpVec.push_back(path[i]);
		Res.push_back(tmpVec);
		return;
	}
	if(curWeight > s || root[ID].empty())	return ;
	for(i = 0; i < root[ID].size(); i++)
	{
		curWeight += w[root[ID][i]];
		path.push_back(w[root[ID][i]]);
		dfs(root[ID][i], curWeight);
		curWeight -= w[root[ID][i]];
		path.pop_back();
	}
}

int main()
{
	int i,a,b,num,j;
	scanf("%d %d %d", &n, &m, &s);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
	}
	for(i = 1; i <= m; i++)
	{
		scanf("%d %d",&a, &num);
		for(j = 1; j <= num; j++)
		{
			scanf("%d", &b);
			root[a].push_back(b);
		}
	}
	path.push_back(w[0]);
	dfs(0, w[0]);
	for(i = Res.size()-1; i >= 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			int k = 0;
			if(Res[j][k] < Res[j+1][k])
			{
				swap(Res[j] , Res[j+1]);
			}
			else if(Res[j][k] == Res[j+1][k])
			{
				while(k < Res[j].size() && k < Res[j+1].size() && Res[j][k] == Res[j+1][k])
				{
					k++;
				}
				if(k < Res[j].size() && k < Res[j+1].size())
				{
					if(Res[j][k] < Res[j+1][k]){swap(Res[j], Res[j+1]);}
				}
				else if(Res[j+1].size() == k){;}
				else if(Res[j].size() == k){swap(Res[j], Res[j+1]);}
			}
		}
	}
	for(i = 0; i < Res.size(); i++)
	{
		printf("%d", Res[i][0]);
		for(j = 1; j < Res[i].size(); j++)
			printf(" %d", Res[i][j]);
		printf("\n");
	}
	return 0;
}