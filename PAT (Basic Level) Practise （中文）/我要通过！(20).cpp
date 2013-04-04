#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
  int n ;
  cin >> n;
  while(n--)
  {
    string str;
    int p = 0, t = 0;
    cin >> str;
    int len = str.size();
    int ok = 1,i,post,posp;
    for(i = 0; i < len; i++)
    {
      if(!(str[i]== 'P' || str[i] == 'A' || str[i] == 'T'))
        ok = 0;
      if(str[i] == 'P')
      {
        p++;
        posp = i;
      }
      if(str[i] == 'T')
      {
        t++;
        post = i;
      }
    }
    if(!ok)  cout << "NO" << endl;
    else
    {
      int a = posp - 0;
      int c = len - post-1;
      int b = post-posp-1;
      //cout << a << " " << b << " " << c << endl;
      if(c==0&&b>=1&&a==0)
        printf("YES\n");
      else if(c&&c==a*b)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  return 0;
}  