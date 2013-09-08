#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void reverse(string *e, int start , int end)
{
  int i;
  for(i = 0; i <= (end-start)>>1; i++)
  {
    string tmp = e[start+i];
    e[start+i] = e[end-i];
    e[end-i] = tmp;
  }
}
string e[500];
char str[85];
int main()
{
  gets(str);
  int len = strlen(str), lene = 0,i;
  string tmp = ""; 
  for(i = 0; i < len; i++)
  {
    if(str[i] == ' ')
    {
      e[lene++] = tmp;
      tmp = ""; 
    }
    else
    {
      tmp += str[i];
    }
  }
  if(tmp != "")  e[lene++] = tmp;
  reverse(e, 0, lene-1);
  printf("%s", e[0].c_str());
  for(i = 1; i < lene; i++)
    printf(" %s", e[i].c_str());
  printf("\n");
  return 0;
}