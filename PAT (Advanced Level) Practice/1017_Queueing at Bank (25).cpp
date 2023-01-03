//原始版
//fuck   只要除以合法人数   而不是总人数   第一个Sample 老是跑不对， 原因在这。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n,k,i,h,m,s,w,hour;
deque<pair<int,int> > Peo;

int Windows[101];

int cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first < b.first;
}

bool has_Windows(int &win_num)
{
    for(int i = 0; i < k; i++)
    {
        if(Windows[i] == 0)
        {
            win_num = i;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> k;
    memset(Windows, 0, sizeof(Windows));
    int peoNum = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d",&h,&m,&s,&w);
        if(h >= 17 && m >=0 && s >=0)
        {
            continue;
        }
        hour = h*60*60+m*60+s;
        if(w > 60)  w = 60;
        peoNum++;
        Peo.push_back(make_pair(hour, w*60));
    }

    sort(Peo.begin(), Peo.end(), cmp);

    int time = -1;
    int ans = 0;
    while( !Peo.empty() )
    {
        for(i = 0; i < k; i++)
        {
            if(Windows[i] != 0)
                Windows[i]--;
        }

        int win_num;
        while( !Peo.empty() && has_Windows(win_num) && time >= 8*60*60 && time >= Peo[0].first )
        {
            Windows[win_num] = Peo[0].second;
            ans += time - Peo[0].first;
            Peo.pop_front();
        }
        time++;
    }
    if(!peoNum)
        cout << "0.0" << endl;
    else
        printf("%.1lf\n", (double)ans/(peoNum*60.0));
    return 0;
}


/*
//在自己基础上，照着网上的其他人改了下。  窗口其实像上面定义成Int就好了，这个我觉得写的还麻烦了。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int n,k,i,h,m,s,w,hour;
deque<pair<int,int> > Peo;
vector<pair<int,int> > Windows;
vector<pair<int,int> > tmp;

int cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.first < b.first;
}


int main()
{
    cin >> n >> k;
    int peoNum = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d",&h,&m,&s,&w);
        if(h >= 17 && m >=0 && s >=0)
        {
            continue;
        }
        hour = h*60*60+m*60+s;
        if(w > 60)  w = 60;
        peoNum++;
        Peo.push_back(make_pair(hour, w*60));
    }

    sort(Peo.begin(), Peo.end(), cmp);

    int time = -1;
    int ans = 0;
    int valid = k;
    while( !Peo.empty() )
    {
        for(i = 0; i < Windows.size();i++)
        {
            Windows[i].second --;
            if(Windows[i].second == 0)
                valid++;
            else
                tmp.push_back(Windows[i]);
        }
        Windows= tmp;
        tmp.clear();
        while(valid > 0 && Peo.size() > 0 && time >= Peo[0].first && time >= 8*60*60)
        {
                Windows.push_back(Peo[0]);
                valid--;
                ans += time - Peo[0].first;
                Peo.pop_front();
        }
        time++;
    }
    if(peoNum == 0) cout << "0.0" << endl;
    else
    {
        printf("%.1f\n",ans/(60.0*peoNum));
    }
    return 0;
}



*/
