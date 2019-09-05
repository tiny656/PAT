/*
map 用作hash 来记录个数了。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <set>
#include <deque>
using namespace std;

static inline bool get(int &v)//fast to read huge input
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

map<int,int> cnt;
int a[100005];
int main()
{
	int n, key, i;
	get(n); get(key);
	for(i = 0; i < n; i++)
	{
		get(a[i]);
		cnt[a[i]]++;
	}
	sort(a, a+n);
	for(i = 0; i < n; i++)
	{
		int cur = a[i];
		if(cur != key-cur && cnt[key-cur] > 0)
		{
			printf("%d %d\n", cur, key-cur);
			return 0;
		}
		else if(cur == key-cur && cnt[key-cur] >= 2)
		{
			printf("%d %d\n", cur, cur);
			return 0;
		}
	}
	puts("No Solution");
	return 0;
}
