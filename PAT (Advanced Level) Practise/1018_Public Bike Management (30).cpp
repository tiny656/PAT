//理解题目有误啊。
//Back 那个前面计算有问题   5和7测试用例一直过不了，
//后面参考了http://linest.iteye.com/blog/1423959
//然后拿下了。
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

int c,s,n;
int numOfBike[1000];
vector<pair<int,int> > adj[1000];
int vis[1000];
int collect[1000];
deque<int> path;
vector<int> pathAns;
int minDis,minNumBikeSend, minNumBikeBack;
inline void saveAns()
{
    int i;
    pathAns.clear();
    for(i = 0; i < path.size(); i++)
    {
        //cout << path[i] << endl;
        pathAns.push_back(path[i]);
    }
}

void dfs(int ID, int curDis, int curNum,int cnt)
{
    int i;
    if(ID == s)
    {

        memset(collect,0,sizeof(collect));
        for(i = 0; i < path.size(); i++)
            collect[path[i]] = numOfBike[path[i]] - c/2;

        int Send = 0;
        int Back = 0;
        int tmp;
        if(curDis <= minDis)
        {
            for(i = 1 ;i <= n ;i++)
            {
                tmp = Back + collect[i];
                if(tmp < 0)
                {
                    Send -= tmp;
                    Back = 0;
                }
                else if(tmp >= 0)
                {
                    Back = tmp;
                }
            }
        }

        //路径更小
        if(curDis < minDis)
        {
            minDis = curDis;
            minNumBikeSend = Send;
            minNumBikeBack = Back;
            saveAns();
        }
        else if(curDis == minDis)
        {
            if(Send < minNumBikeSend)
            {
                minNumBikeSend = Send;
                minNumBikeBack = Back;
                saveAns();
            }
            else if(Send == minNumBikeSend && Back < minNumBikeBack)
            {
                minNumBikeBack = Back;
                saveAns();
            }
        }
        return;
    }


    for(i = 0; i < adj[ID].size(); i++)
    {
        if(!vis[adj[ID][i].first] && curDis + adj[ID][i].second <= minDis)
        {
            //cout << "访问" << adj[ID][i].first << endl;
            vis[adj[ID][i].first] = 1;
            path.push_back(adj[ID][i].first);
            dfs(adj[ID][i].first, curDis + adj[ID][i].second, curNum+numOfBike[adj[ID][i].first], cnt+1);
            path.pop_back();
            vis[adj[ID][i].first] = 0;
            //cout << "回溯" << adj[ID][i].first << endl;
        }
    }
}



int main()
{
    int i,a,b,w,m;;
    cin >> c >> n >> s >> m;

    for(i = 0; i <= n; i++)
    {
        vis[i] = 0;
    }

    for(i = 1; i <= n; i++)
        cin >> numOfBike[i];

    for(i = 1; i <= m; i++)
    {
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b,w));
        adj[b].push_back(make_pair(a,w));
    }

    minDis = 0x3fffffff;
    minNumBikeSend = 0x3fffffff;
    minNumBikeBack = 0x3fffffff;

    vis[0] = 1;
    numOfBike[0] = 0;
    path.push_back(0);
    dfs(0, 0, 0, 0);

    cout << minNumBikeSend << " ";
    if(pathAns.size() == 0)
    {
        cout << minNumBikeBack << endl;
    }
    else
    {
        cout << pathAns[0];
        for(i = 1; i < pathAns.size(); i++)
        {
            cout << "->" << pathAns[i];
        }
        cout << " " << minNumBikeBack << endl;
    }

    return 0;
}
