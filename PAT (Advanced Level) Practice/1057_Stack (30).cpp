#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <stack>
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
树状数组求第k小元素
*/
const int maxn = 100005;
int n,k;   
int c[maxn];   

int lowbit(int x){ return x&-x; }   
void insert(int x,int t){ while(x<maxn){ c[x]+=t; x+=lowbit(x); } }   
int find(int k)
{   
	int cnt=0,ans=0;   
	for(int i=20;i>=0;i--)
	{   
		ans+=(1<<i);   
		if(ans>=maxn || cnt+c[ans]>=k)ans-=(1<<i);   
		else cnt+=c[ans];
	}   
	return ans+1;   
} 
stack<int> s;
int main()
{
	memset(c, 0, sizeof(c));
	int n,i,val;
	char str[100];
	get(n);
	for(i = 1; i <= n; i++)
	{
		gets(str);
		if(!strcmp(str,"Pop"))
		{
			if(s.empty())	printf("Invalid\n");
			else
			{
				printf("%d\n", s.top()); 
				insert(s.top(), -1);
				s.pop();
			}
		}
		else if(!strcmp(str, "PeekMedian"))
		{
			if(s.empty())	printf("Invalid\n");
			else{printf("%d\n", find((s.size()+1)>>1));}
		}
		else
		{
			sscanf(str, "Push %d", &val);
			insert(val, 1);
			s.push(val);
		}
	}
	return 0;
}
