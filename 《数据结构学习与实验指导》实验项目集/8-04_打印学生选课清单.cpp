#include <stdio.h>
#include <map>
#include <set>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool get(int& a)
{
  if( scanf("%d",&a) == EOF ) return false ;
  return true ;
}

const int maxn = 2500*200 ;
int nimei[maxn] , cnt ;
int id[26][26][26][10] ;

int bs(int key,int l,int r)
{
  int mid ;
  while ( l <= r )
  {
    mid = ( l + r ) >> 1 ;
    if( nimei[mid] > key )
      r = mid - 1 ;
    else
      l = mid + 1 ;
  }
  return r ;
}

int main()
{
  int n , m ;
  get(n); get(m);
  int i , j , k ;
  int idCnt = 1 ;
  cnt = 0 ;
  for ( i = 0 ; i < m ; i++)
  {
    get(j); get(k);
    char str[16] ;
    while(k--)
    {
      scanf("%s",str);
      int &temp = id[str[0]-'A'][str[1]-'A'][str[2]-'A'][str[3]^48] ;
      if( temp == 0 )
        temp = idCnt++;
      nimei[cnt++] = temp*2500+j ;
    }
  }
  sort(nimei,nimei+cnt);
  char name[16] ;
  while(n--)
  {
    scanf("%s",name);
    int t = id[name[0]-'A'][name[1]-'A'][name[2]-'A'][name[3]^48] ;
    if( t == 0 )
    {
      printf("%s 0\n",name);
      continue;
    }
    j = bs(t*2500,0,cnt-1) ;
    k = bs((t+1)*2500,j,cnt-1);
    printf("%s %d",name,k-j);
    for ( j++; j <= k ; j++)
    {
      printf(" %d",nimei[j]-t*2500);
    }
    puts("");
  }
  return 0;
}