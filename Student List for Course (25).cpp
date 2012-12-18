#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
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

struct f
{
	char name[5];
	int len;
	int cour[20];
}e;

int cmp(const f &a, const f &b)
{
	return strcmp(a.name,b.name) < 0;
}

vector<f> elem;
char ccName[40001][5];
vector<int> res[40001];
int main()
{
	int n,m,i,j;
	get(n);get(m);
	for(i = 0; i < n; i++)
	{
		scanf("%s", e.name);
		get(e.len);
		for(j = 0; j < e.len; j++)
		{
			get(e.cour[j]);
		}
		elem.push_back(e);
	}

	sort(elem.begin(), elem.end(), cmp);

	for(i = 0; i < n; i++)
	{
		strcpy(ccName[i], elem[i].name);
		for(j = 0; j < elem[i].len; j++)
		{
			res[elem[i].cour[j]].push_back(i);
		}
	}

	for(i = 1; i <= m; i++)
	{
		printf("%d %d\n",i,res[i].size());
		for(j = 0; j < res[i].size(); j++)
		{
			printf("%s\n", ccName[res[i][j]]);
		}
	}
	return 0;
}