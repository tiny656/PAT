/*
累计 距离  ，用距离差 表示 某一段的距离
因为是环 所以 用总长减去当前段距离，就是相反方向段的距离
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

int d[100005];
int main()
{
  int n,i,q,a,b,e,tot = 0;
  get(n);
  d[0] = 0;
  for(i = 1; i <= n; i++)
  {
    get(e);
    d[i] += d[i-1] + e;
    tot += e;
  }
  
  get(q);
  for(i = 1; i <= q; i++)
  {
    get(a);get(b);
    int start = min(a, b);
    int end = max(a, b) - 1;
    int dis;
    if(start > end)  dis = 0;
    else dis = d[end] - d[start-1];
    printf("%d\n", min(dis, tot-dis));
  }
  return 0;
}