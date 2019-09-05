#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <map>
#include <cstring>
using namespace std;
 
//1.按考场和分数排1次 计算考场名次 
//2.按整体分数 排1次  计算总名次
struct info
{
	string ID;
	int pts;
	int finalRank;
	int examNo;
	int examRank;
}tmp;
vector<info> ans; 

int cmp1(const info &a, const info &b)
{
	if(a.examNo == b.examNo)
		return a.pts > b.pts;
	else 	return a.examNo < b.examNo;
}
int cmp2(const info &a, const info &b)
{
	if(a.pts== b.pts)	return a.ID < b.ID;
	else return a.pts > b.pts;
}
int NumPeo[101];

int main()
{
	int n,i,j,k,lvl,cnt,pts;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		NumPeo[i] = k+NumPeo[i-1];
		for(j = 1; j <= k; j++)
		{
			cin >> tmp.ID;
			scanf("%d", &tmp.pts);
			tmp.examNo = i;
			ans.push_back(tmp);
		}		
	}
	sort(ans.begin(), ans.end(), cmp1);
	lvl = 1;
	cnt = 0;
	pts = ans[0].pts;
	for(i = 0,j = 1; i < ans.size(); i++)
	{
		if(ans[i].pts < pts)
		{
			lvl += cnt;
			ans[i].examRank = lvl;
			cnt = 1;
		 	pts = ans[i].pts;
		}	
		else
		{
			ans[i].examRank = lvl;
			cnt++;	
		}
		if(i == NumPeo[j]-1)
		{
			lvl = 1;
			cnt = 0;
			pts = ans[i+1].pts;
			j++;
		}
	}
	sort(ans.begin(), ans.end(), cmp2);
	lvl = 1;
	cnt = 0;
	pts = ans[0].pts;
	for(i = 0; i < ans.size(); i++)
	{
		if(ans[i].pts < pts)
		{
			lvl += cnt;
			ans[i].finalRank = lvl;
			cnt = 1;
		 	pts = ans[i].pts;
		}	
		else
		{
			ans[i].finalRank = lvl;
			cnt++;	
		}
	}
	printf("%d\n", ans.size());
	for(i = 0; i < ans.size(); i++)
	{
		cout << ans[i].ID;
		printf(" %d %d %d\n", ans[i].finalRank, ans[i].examNo, ans[i].examRank);	
	}
	return 0;	
}