#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;

queue< pair<int,int> > Peo;
queue< pair<int,int> > q[25];
pair<int,int> Windows[25];
map<int,int> ans;
int n,m,k,query,i,j,val;

//判断是否有窗口为空
bool has_Windows(int &win_num)
{
    for(int i = 1; i <= n; i++)
    {
        if(Windows[i].second == 0 && q[i].size() > 0)
        {
            win_num = i;
            return true;
        }
    }
    return false;
}

//补充排队人数
bool has_Queue()
{
    for(int i = 1; i <= n; i++)
    {
        if(q[i].size() < m)
        {
            return true;
        }
    }
    return false;
}


int main()
{

    int k,query,i,j,val;
    cin >> n >> m >> k >> query;

    for(i = 1; i <= n; i++)
    {
        Windows[i].second = 0;
    }

    for(i = 1; i <= k; i++)
    {
        cin >> val;
        Peo.push( make_pair(i,val) );
    }

    //初始化各个窗口前的排队队列
    while(q[n].size() != m && !Peo.empty())
    {
        for(i = 1; i <= n; i++)
        {
            if(q[i].size() < m && !Peo.empty())
            {
                q[i].push(Peo.front());
                Peo.pop();
            }
        }
    }

    int time = 8*60;//起始时间
    while(time < 17*60)
    {
        //窗口工作
        for(i = 1; i <= n; i++)
        {
            if(Windows[i].second != 0)
            {
                Windows[i].second--;
                if(Windows[i].second == 0)
                {
                    q[i].pop();
                }
            }
        }

        //窗口空闲，调入排队的人
        int win_num = -1;
        while(has_Windows(win_num))
        {
            Windows[win_num] = q[win_num].front();
            //cout << "人员" <<q[win_num].front().first << "进入窗口" <<win_num<<endl;
            //cout << "人员" << q[win_num].front().first << "将在"
            //     <<(q[win_num].front().second+time )/60<< ":"<<(q[win_num].front().second+time )%60<<"完成"<<endl;
            //cout << endl;
            ans[q[win_num].front().first] = q[win_num].front().second+time;
        }
        //补充窗口前排队人数
        while(has_Queue())
        {
            int minSize = 100000;
            int index = -1;
            for(i = 1; i <= n; i++)
            {
                if(q[i].size() < m && q[i].size() < minSize)
                {
                    minSize = q[i].size();
                    index = i;
                }
            }
            //cout  << time << " " << index << " " << minSize << endl;
            //cout << endl;

            if(!Peo.empty() && index != -1)
            {
                q[index].push(Peo.front());
                //cout << "人员" <<Peo.front().first << "进入队列" <<index<<endl;
                Peo.pop();
            }
            else
            {
                break;
            }
        }
        time++;
    }
    int ask;
    for(i = 1; i <= query; i++)
    {
        cin >> ask;
        if(ans[ask] != 0)
            printf("%02d:%02d\n", ans[ask]/60, ans[ask]%60);
        else
            puts("Sorry");
    }

    return 0;
}
