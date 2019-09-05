#include <cstdio>
#include <iostream>
#include <map>
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
用map来计数，超过m*n/2就是答案
*/
long long matrix[805][605];
map<long long,int> cnt;

int main()
{
	int m,n,i,j;
	long long tmp,ans;
	get(m),get(n);
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%lld", &tmp);
			cnt[tmp]++;
			if(cnt[tmp] > (m*n)/2)
				ans = tmp;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
