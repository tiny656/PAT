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
参考别人好思路,先排序,依据完全二叉树和二叉排序树中序遍历的有序性特征来构造
构造完全二叉树依据堆的思想,左孩子2*cur,右孩子2*cur+1,完全二叉树恰好是一个完整数组
*/

int e[1001],n,m,ans[1001];

void f(int cur)
{
	if( cur*2 <= n )
		f(2*cur);
	ans[cur] = e[m++];
	if( cur*2+1 <= n )
		f(2*cur+1);
}

int main()
{
	int i;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
		scanf("%d",&e[i]);
	sort(e,e+n);
	m = 0;
	f(1);
	printf("%d", ans[1]);
	for(i = 2; i <= n; i++)
	{
		printf(" %d", ans[i]);
	}
	puts("");
	return 0;
}