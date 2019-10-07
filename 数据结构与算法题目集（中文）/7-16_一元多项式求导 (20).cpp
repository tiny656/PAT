#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector> 
#include <map>
using namespace std;

struct node
{//stand for aX^b 
    int a;
    int b;
}tmp;
vector<node> formula;
const int re = 1005;
int fuck[5005];
vector<pair<int,int> >ans;
char str[500000];


int main()
{
    char c;
    int curNum = 0;	//0 for a, 1 for b 
    int val = 0;	//stand for value 
    // WTF , EOF end the input. 
    while(scanf("%d", &val) != EOF)
    {
        if(!curNum)	tmp.a= val;
        else	
        {
            tmp.b= val;	
            formula.push_back(tmp);
        }
        curNum = !curNum;
    }
    int i = 0;
    int len = formula.size();
    memset(fuck,0,sizeof(0));
    for(i = 0; i < len; i++)
    {
        fuck[formula[i].b-1+re] += formula[i].a*formula[i].b;
    }
    for(i = 1005 + re; i >= 1005 - re ; i--)
    {
        if(fuck[i] == 0 || i == -1)	continue; 
        else	ans.push_back(make_pair(fuck[i], i-re));
    }
    if(ans.size() == 0)	printf("0 0\n");
    else
    {
        printf("%d %d", ans[0].first, ans[0].second);
        for(i = 1; i < ans.size(); i++)
        {
            printf(" %d %d", ans[i].first, ans[i].second);
        }
        printf("\n");
    }
    return 0;
}