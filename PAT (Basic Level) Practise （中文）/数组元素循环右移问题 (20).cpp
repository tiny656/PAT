#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

void reverse(int *elem, int start , int end)
{
  int i;
  for(i = 0; i <= (end-start)>>1; i++)
  {
    int tmp = elem[start+i];
    elem[start+i] = elem[end-i];
    elem[end-i] = tmp;
  }
}

void move(int *elem, int n, int dis)
{
  dis = dis % n;
  reverse(elem, 0, n-dis-1);
  reverse(elem, n-dis,n-1);
  reverse(elem, 0, n-1);
}

int a[105];
int main()
{
  int n, dis,i;
  scanf("%d %d", &n, &dis);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  move(a, n, dis);
  printf("%d", a[0]);
  for(i = 1; i < n; i++)  printf(" %d", a[i]);
  printf("\n");
  return 0;
}