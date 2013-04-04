#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;

int price[25];

struct tip
{
    string Name;
    string state;
    int month,day;
    int hour,minute;
    int valid;
}tmp;

struct e
{
    int month;
    int day;
    int hour;
    int minute;
}tmpe;

int i,n;
vector<tip> Info;
map<string, vector<e> >ans;

int cmp(const tip &a, const tip &b)
{
    if(a.month == b.month)
    {
        if(a.day == b.day)
        {
            return (a.hour*60+a.minute) < (b.hour*60+b.minute);
        }
        return a.day < b.day;
    }
    return a.month < b.month;
}

bool hasValid(int &validNum)
{
    for(i = 0; i < n; i++)
    {
        if(Info[i].state == "on-line" && Info[i].valid == 1)
        {
            validNum = i;
            return true;
        }
    }
    return false;
}

//计算一条有效电话记录的时长和费用，并返回费用
double charge(e start, e end)
{
      double cost = 0;
      long time = 0;

      while(start.day < end.day)
      {
          time += (60 - start.minute);
          cost += (60 - start.minute) * price[start.hour];
          start.minute = 0; start.hour ++;
          time += 60 * (24 - start.hour);
          while(start.hour < 24)
          {
              cost += 60 * price[start.hour];
              start.hour ++;
          }
          start.hour = 0;
          start.day++;
      }
      while(start.hour < end.hour)
      {
          time += (60 - start.minute);
          cost += (60 - start.minute) * price[start.hour];
          start.minute = 0;
          start.hour++;
      }
      time += (end.minute - start.minute);
      cost += price[end.hour] * (end.minute - start.minute);

      printf("%ld $%.2lf\n", time, cost / 100);

      return cost / 100;
 }

int main()
{
    for(i = 0; i < 24; i++)
    {
        cin >> price[i];
    }
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> tmp.Name;
        scanf(" %d:%d:%d:%d ",&tmp.month,&tmp.day,&tmp.hour,&tmp.minute);
        cin >> tmp.state;
        tmp.valid = 1;
        Info.push_back(tmp);
    }

    sort(Info.begin(),Info.end(),cmp);

/*
    for(i = 0; i < n; i++)
    {
        cout << Info[i].Name;
        printf(" %d:%d:%d:%d ",Info[i].month,Info[i].day,Info[i].hour,Info[i].minute);
        cout << Info[i].state << " ";
        cout << Info[i].valid << endl;
    }
*/

    //寻找合法的电话记录
    int validNum = -1;
    while(hasValid(validNum))
    {

        string cur = Info[validNum].Name;
        Info[validNum].valid = 0;
        //cout << "当前寻找到合法号码" << validNum << "  姓名为" << cur << endl;

        int ok = 0,pair = -1;
        for(i = validNum+1; i < n; i++)
        {
            if(Info[i].Name == cur)
            {
                pair = i;
                if(Info[i].state == "off-line")
                {
                    ok = 1;

                    tmpe.month = Info[validNum].month;
                    tmpe.day = Info[validNum].day;
                    tmpe.hour = Info[validNum].hour;
                    tmpe.minute = Info[validNum].minute;
                    ans[cur].push_back(tmpe);

                    tmpe.month = Info[pair].month;
                    tmpe.day = Info[pair].day;
                    tmpe.hour = Info[pair].hour;
                    tmpe.minute = Info[pair].minute;
                    ans[cur].push_back(tmpe);
                    //cout << "找到合法配对" << pair << endl;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
        if(ok)  Info[pair].valid = 0;
    }
    for(map<string, vector<e> >::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        if(ans[iter->first].size() > 0)
        {
            cout << iter->first;
            printf(" %02d\n", ans[iter->first][0].month);
            double total = 0;
            for(i = 0; i < ans[iter->first].size()-1; i += 2)
            {
                printf("%02d:%02d:%02d %02d:%02d:%02d ",ans[iter->first][i].day,ans[iter->first][i].hour,ans[iter->first][i].minute,ans[iter->first][i+1].day,ans[iter->first][i+1].hour,ans[iter->first][i+1].minute);
                total += charge(ans[iter->first][i], ans[iter->first][i+1]);
            }
            printf("Total amount: $%.2lf\n",total);
        }
    }

    return 0;
}
