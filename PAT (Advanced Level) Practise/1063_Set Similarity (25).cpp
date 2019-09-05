#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

/*
用Map或者Set来进行集合的统计操作,应该都可以水过
*/

map<int,int> Rec[55];

int main()
{
	int n,m,e,i,j,a,b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &m);
		for(j = 1; j <= m; j++)
		{
			scanf("%d", &e);
			Rec[i][e]++;
		}
	}
	
	int askN;
	scanf("%d", &askN);
	for(i = 1; i <= askN; i++)
	{
		scanf("%d %d",&a,&b);
		int lena = Rec[a].size();
		int lenb = Rec[b].size();
		int len = min(lena,lenb);
		int flag = (len == lena ? 0 : 1);
		int Nc = 0, Nt = 0;
		if(!flag)
		{
			map<int,int>::iterator iter;
			for(iter = Rec[a].begin(); iter != Rec[a].end(); iter++)
			{
				if ( Rec[b].find(iter->first) != Rec[b].end() )	Nc++;
				else Nt++;
				
			}
			Nt += Rec[b].size();
		}
		else
		{
			map<int,int>::iterator iter;
			for(iter = Rec[b].begin(); iter != Rec[b].end(); iter++)
			{
				if ( Rec[a].find(iter->first) != Rec[a].end() )	Nc++;
				else Nt++;
			}
			Nt += Rec[a].size();
		}
		printf("%.1lf%%\n", ((double)Nc/(double)Nt)*100.0);
	}
	
	return 0;
}
/*
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
*/