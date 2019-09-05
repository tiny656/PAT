#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static inline bool get(int &v)
{
	int s = 1, c;
	while(!isdigit(c = getchar())&&c != '-')
	{
		if(c == EOF)
			break ;
	}
	if(c == EOF) return 0;
	if(c == '-') s = 0 , v = 0;
	else v = c^48;
	for(;isdigit(c = getchar());v = (v << 1) + (v << 3) + (c ^ 48));
	v = (s ? v : -v);
	return 1 ;
}
/*
shit.简单的模拟题，题意看着太蛋疼了。
但是，如果在一个group中，有最重的体重有多余一个的，需要一起晋级。
*/
int w[1005];
int ord[1005];
int ans[1005];
vector<pair<int,int> > v;
vector<pair<int,int> > tmp;
vector<pair<int,int> > ppp;
int main()
{
	int n,p,i,j;
	get(n),get(p);
	p = min(n,p);
	for(i = 0; i < n; i++)
	{
		get(w[i]);
	}
	for(i = 0;i < n; i++)
	{
		get(ord[i]);
		v.push_back(make_pair(ord[i], w[ord[i]]));
	}
	if(p == 1 || p == 0)
	{
		printf("1");
		for(i = 1; i < n; i++)
			printf(" 1");
		puts("");
		return 0;
	}
	int group = (n%p == 0) ? n/p : n/p+1;
	while(group != 1)
	{
		tmp.clear();
		int i = 0;
		int cnt = 0;
		int max = -1;
		int index = -1;

		while(i < v.size())
		{
			ans[v[i].first] = group+1;
			if(v[i].second > max)
			{
				max = v[i].second;
				index = v[i].first;
				ppp.clear();
				ppp.push_back(make_pair(v[i].first, max));
			}
			else if(v[i].second == max)
			{
				ppp.push_back(make_pair(index,max));
			}
			i++;
			cnt++;
			if(cnt == p)
			{
				cnt = 0;
				for(j = 0; j < ppp.size(); j++)
					tmp.push_back(ppp[j]);
				ppp.clear();
				max = -1;
				index = -1;
			}
		}
		if(cnt != p)
		{
			cnt = 0;
			for(j = 0; j < ppp.size(); j++)
				tmp.push_back(ppp[j]);
			ppp.clear();
			max = -1;
			index = -1;
		}
		v.clear();
		for(j = 0; j < tmp.size(); j++)
		{
			v.push_back(tmp[j]);
		}
		group = (v.size()%p == 0) ? v.size()/p : (v.size()/p+1);
	}
	int max = -1, index = -1;
	for(i = 0; i < v.size(); i++)
	{
		ans[v[i].first] = 2;
		if(v[i].second > max)
		{
			index = v[i].first;
			max = v[i].second;
		}
	}
	ans[index] = 1;
	printf("%d", ans[0]);
	for(i = 1; i < n; i++)
		printf(" %d", ans[i]);
	printf("\n");

	return 0;
}
