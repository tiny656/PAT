#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string name[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
vector<string> ans;
int main()
{
  char c;
  int sum = 0;
  while((c = getchar()) != '\n')
  {
    sum += c-'0';
  }
  if(!sum)  ans.push_back( name[0] );
  while(sum)
  {
    ans.push_back( name[ sum%10 ] );
    sum /= 10;
  }
  cout << ans[ans.size()-1];
  for(int i = ans.size()-2; i >= 0; i--)
    cout << " " << ans[i];
  cout << endl;
  return 0;
}