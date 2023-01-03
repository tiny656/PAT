#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <queue>
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
用age为索引，建立结构，对[1-200]的age排序，在用优先队列，找出前num个需要的元素
*/
struct info
{
	char name[20];
	int age;
	int val;
	
}tmp;


vector<info> elem[205];
priority_queue<info> q;
int addNum[205];

bool operator < (info a, info b)
{
	if(a.val == b.val)
	{
		if(a.age == b.age)	return strcmp(a.name,b.name)>=0;
		else	return a.age > b.age;
	}
	else return a.val < b.val;
}


int cmp(const info &a, const info &b)
{
	if(a.val == b.val)
	{
		if(a.age == b.age)	return strcmp(a.name,b.name)<0;
		else	return a.age < b.age;
	}
	else return a.val > b.val;
}


int main()
{
	int n,k,i,num,a,b,j,kk;
	get(n), get(k);
	for(i = 1; i <= n; i++)
	{
		scanf("%s", tmp.name);
		get(tmp.age),get(tmp.val);
		elem[tmp.age].push_back(tmp);
	}
	
	for(i = 1; i <= 200; i++)
		sort(elem[i].begin(), elem[i].end(), cmp);

	for(i = 1; i <= k; i++)
	{
		while(!q.empty()) q.pop();
		get(num),get(a),get(b);	
		printf("Case #%d:\n", i);
		int cnt = 0;
		for(j = a; j <= b; j++)
		{
			if( elem[j].size() )//加入所有a-b年龄的第一个元素
			{
				addNum[j] = 1;
				tmp.val = elem[j][0].val;
				tmp.age = j; 
				strcpy(tmp.name, elem[j][0].name);
				q.push(tmp);
			}
		}
		while(cnt < num && !q.empty())
		{
			info fuck = q.top(); 
			q.pop();
			if(addNum[fuck.age] < elem[fuck.age].size())
			{
				tmp.age = fuck.age;
				strcpy(tmp.name, elem[fuck.age][addNum[fuck.age]].name);
				tmp.val = elem[fuck.age][addNum[fuck.age]].val;
				addNum[fuck.age]++;
				q.push(tmp);
			}
			printf("%s %d %d\n", fuck.name, fuck.age, fuck.val);
			cnt++;
		}
		if(cnt == 0)	puts("None");
	}
	return 0;
}
