#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <cstring>
using namespace std;


map<string, int> weight;
map<string, vector<string> > adj;
map<string, int> vis;
map<string, int> ans;
string strAns;
int WeightAns;
int totalWeight;
int cnt;

void dfs(string str)
{
    vis[str] = 1;
    cnt++;
    totalWeight += weight[str];
    if(WeightAns < weight[str])
    {
        WeightAns = weight[str];
        strAns = str;
    }
    else if(WeightAns == weight[str])
    {
        strAns = str < strAns ? str : strAns;
    }

    for(vector<string>::iterator iter = adj[str].begin(); iter != adj[str].end(); iter++)
    {
        if( !vis[*iter] )
        {
            dfs(*iter);
        }
    }
}


int main()
{
    int n,k,i;
    string A,B;
    int w;

    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
        cin >> A >> B >> w;
        weight[A] += w;
        weight[B] += w;
        adj[A].push_back(B);
        adj[B].push_back(A);
        vis[A] = vis[B] = 0;
    }

    for(map<string, int>::iterator iter = vis.begin(); iter != vis.end(); iter++)
    {
        if(!vis[ iter->first ])
        {
            strAns = "";
            WeightAns = 0;
            totalWeight = 0;
            cnt = 0;
            dfs(iter->first);
            if(cnt > 2 && totalWeight/2 > k)
            {
                ans[strAns] = cnt;
            }
        }
    }

    cout << ans.size() << endl;
    for(map<string, int>::iterator iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}
