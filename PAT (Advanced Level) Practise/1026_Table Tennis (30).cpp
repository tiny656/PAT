#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

#define maxn 10005

struct info
{
    int comeTime;
    int serveTime;
    int tag;
}tmp;

deque<info> noVIP;//非贵宾队列
deque<info> VIP;//贵宾队列
int table[maxn];//记录桌子当前服务还剩多少时间
int numsTableServed[maxn];//记录桌子服务的客户数量
int VIPTableCol[maxn];
int n,hh,mm,ss,tableNums,vipTableNums,id;

int cmp(const info &a, const info &b)
{
    return a.comeTime < b.comeTime;
}

bool isVIPCome(int curTime)
{
    int i;
    for(i = 0; i < VIP.size(); i++)
    {
        if(VIP[i].comeTime <= curTime)
        {
            return true;
        }
    }
    return false;
}

bool hasVIPTable(int &ID)
{
    int i;
    for(i = 0; i < vipTableNums; i++)
    {
        if(table[ VIPTableCol[i] ] == 0)
        {
            ID = VIPTableCol[i];
            return true;
        }
    }
    return false;
}

bool hasNext(int cur, int &from)
{
    info tmp1, tmp2;
    if(!noVIP.empty() && !VIP.empty())
    {
        tmp1 = noVIP.front();
        tmp2 = VIP.front();
        if(tmp1.comeTime <= cur && tmp2.comeTime <= cur)
        {
            if(tmp1.comeTime < tmp2.comeTime)
            {
                from = 0;
                return true;
            }
            else
            {
                from = 1;
                return true;
            }
        }
        else if(tmp1.comeTime <= cur && tmp2.comeTime > cur)
        {
            from = 0;
            return true;
        }
        else if(tmp2.comeTime <= cur && tmp1.comeTime > cur)
        {
            from = 1;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(!noVIP.empty() && VIP.empty())
    {
        tmp1 = noVIP.front();
        if(tmp1.comeTime <= cur)
        {
            from = 0;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(noVIP.empty() && !VIP.empty())
    {
        tmp2 = VIP.front();
        if(tmp2.comeTime <= cur)
        {
            from = 1;
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool hasTable(int &ID)
{
    int i;
    for(i = 1; i <= tableNums; i++)
    {
        if(table[i] == 0)
        {
            ID = i;
            return true;
        }
    }
    return false;
}

int main()
{
    int i;
    memset(table, 0, sizeof(table));
    memset(numsTableServed, 0, sizeof(numsTableServed));

    cin >> n;
    for(i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &tmp.serveTime, &tmp.tag);
        tmp.serveTime = tmp.serveTime > 120 ? 120 : tmp.serveTime;
        tmp.serveTime *= 60;
        tmp.comeTime = hh*60*60+mm*60+ss;
        if(tmp.tag)
        {
            VIP.push_back(tmp);
        }
        else
        {
            noVIP.push_back(tmp);
        }
    }
    cin >> tableNums;
    cin >> vipTableNums;
    for(i = 0; i < vipTableNums; i++)
    {
        cin >> id;
        VIPTableCol[i] = id;
    }
    sort(noVIP.begin(), noVIP.end(), cmp);
    sort(VIP.begin(), VIP.end(), cmp);
    sort(VIPTableCol, VIPTableCol+vipTableNums);
    info curVIP;
    int earlyPairFrom;
    int TableID;
    int cur = 8*60*60;
    while(cur < 21*60*60)
    {
        for(i = 1; i <= tableNums; i++)
        {
            if(table[i] != 0)
                table[i]--;
        }

        while(isVIPCome(cur))//检查是否有其他VIP到
        {
            //printf("当前时间%d, 有VIP到\n", cur);
            if(hasVIPTable(TableID))//检查是否有VIP桌子空闲
            {
                info curPair = VIP.front();
                VIP.pop_front();
                table[TableID] = curPair.serveTime;
                numsTableServed[TableID]++;

                //printf("为VIP客户分配桌子%d\n", TableID);

                printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d\n", curPair.comeTime/60/60,
                       curPair.comeTime/60%60, curPair.comeTime%60, cur/60/60, cur/60%60,
                       cur%60, (cur-curPair.comeTime+30)/60);
            }
            else
            {
                break;
            }
        }

        while(hasNext(cur, earlyPairFrom))//找出已经到了时间最早的pair
        {
            if(earlyPairFrom)//如果最早的是个VIP
            {
                if(hasTable(TableID))//检查是否有桌子
                {
                    info curPair;
                    curPair = VIP.front(); VIP.pop_front();
                    table[TableID] = curPair.serveTime;
                    numsTableServed[TableID]++;
                    printf("%.2d:%.2d:%.2d %02d:%.2d:%.2d %d\n", curPair.comeTime/60/60,
                       curPair.comeTime/60%60, curPair.comeTime%60, cur/60/60, cur/60%60,
                       cur%60, (cur-curPair.comeTime+30)/60);
                }
                else
                {
                    break;
                }

            }
            else//最早的不是个VIP
            {
                while(isVIPCome(cur))//检查是否有其他VIP到
                {
                    //printf("当前时间%d, 有VIP到\n", cur);
                    if(hasVIPTable(TableID))//检查是否有VIP桌子空闲
                    {
                        info curPair = VIP.front();
                        VIP.pop_front();
                        table[TableID] = curPair.serveTime;
                        numsTableServed[TableID]++;

                        //printf("为VIP客户分配桌子%d\n", TableID);

                        printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d\n", curPair.comeTime/60/60,
                               curPair.comeTime/60%60, curPair.comeTime%60, cur/60/60, cur/60%60,
                               cur%60, (cur-curPair.comeTime+30)/60);
                    }
                    else
                    {
                        break;
                    }
                }
                //为屌丝分配桌子
                if(hasTable(TableID))//检查是否有桌子
                {
                    info curPair;
                    curPair = noVIP.front(); noVIP.pop_front();

                    table[TableID] = curPair.serveTime;
                    numsTableServed[TableID]++;
                    //printf("为noVIP客户分配桌子%d\n", TableID);

                    printf("%.2d:%.2d:%.2d %.2d:%.2d:%.2d %d\n", curPair.comeTime/60/60,
                           curPair.comeTime/60%60, curPair.comeTime%60, cur/60/60, cur/60%60,
                           cur%60, (cur-curPair.comeTime+30)/60);
                }
                else
                {
                    break;
                }
            }
        }
        cur++;
    }
    printf("%d", numsTableServed[1]);
    for(i = 2; i <= tableNums; i++)
    {
        printf(" %d", numsTableServed[i]);
    }
    printf("\n");
    return 0;
}
