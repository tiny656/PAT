#include <cstdio>
#include <cstring>
using namespace std;

bool is_prime[500001];
int prime[500001];
/*筛法*/
int n, len = 0;
void init()
{
  int i,j;
  memset(is_prime, 0, sizeof(int)*(n+2));
  is_prime[0] = 1; is_prime[1] = 1;
  for(i = 2; i * i <= n; i++)
  {
      if(is_prime[i])  continue;
      for(j = i * i; j <= n; j += i)  is_prime[j] = 1;
  }
  for(i = 1; i <= n; i++)
  {
    if(!is_prime[i])  prime[len++] = i;
  }
}

int main()
{
  int i, ans = 0;
  scanf("%d" ,&n);
  init();
  for(i = 1; i < len && prime[i] <= n; i++)
  {
    if(prime[i]-prime[i-1] == 2)  ans++;  
  }
  printf("%d\n",ans);
  return 0;
}