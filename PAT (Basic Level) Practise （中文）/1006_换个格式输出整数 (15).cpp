#include <cstdio>
using namespace std;

int main()
{
  int n,i;
  scanf("%d" ,&n);
  int B = n/100;
  int S = n/10 % 10;
  int G = n % 10;
  for(i = 1; i <= B; i++)  printf("B");
  for(i = 1; i <= S; i++)  printf("S");
  for(i = 1; i <= G; i++)  printf("%d", i);
  printf("\n");
    return 0;
}