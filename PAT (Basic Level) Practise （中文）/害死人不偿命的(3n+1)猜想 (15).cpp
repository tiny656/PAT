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
  int n,step = 0;
  cin >> n;
  while(n != 1)
  {
    if(n&1)  n = (3*n+1)>>1;
    else  n = n>>1;
    step++;
  }
  cout << step << endl;
  return 0;
}