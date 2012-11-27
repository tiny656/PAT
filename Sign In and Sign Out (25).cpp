#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct info
{
    int start;
    int end;
    string ID;
}tmp;

int cmp1(const info &a, const info &b)
{
    return a.start < b.start;
}
int cmp2(const info &a, const info &b)
{
    return a.end > b.end;
}

int main()
{
    int n,i,h,m,s;
    vector<info> LogInfo;
    while(cin >> n)
    {
        LogInfo.clear();
        for(i = 0; i < n; i++)
        {
            cin >> tmp.ID;
            scanf("%d:%d:%d",&h,&m,&s);
            tmp.start = h*60*60+m*60+s;
            scanf("%d:%d:%d",&h,&m,&s);
            tmp.end = h*60*60+m*60+s;
            LogInfo.push_back(tmp);
            //cout << tmp.ID << " " << tmp.start << " " << tmp.end << endl;
        }
        sort(LogInfo.begin(), LogInfo.end(), cmp1);
        cout << LogInfo[0].ID << " ";
        sort(LogInfo.begin(), LogInfo.end(), cmp2);
        cout << LogInfo[0].ID << endl;
    }
    return 0;
}
