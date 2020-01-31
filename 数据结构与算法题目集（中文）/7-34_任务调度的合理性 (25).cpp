#include <iostream>
#include <vector>
using namespace std;
/*
拓扑排序 
*/
vector<int> AdjList[150];
int in[150];
int vis[150];
bool TopoSort(int n)
{
    int limit = n, i;	
    while(limit--)
    {
        int find = 0;
        for(i = 1; i <= n; i++)
        {
            if(!in[i] && !vis[i])
            {
                find = 1;	
                break;					
            }
        }
        if(!find)	return false;
        int cur = i;
        vis[cur] = 1;
        for(i = 0; i < AdjList[cur].size(); i++)
        {
            in[ AdjList[cur][i] ] --;
        }
    }
    return true;
}

int main()
{
    int n,i,task,k,j;
    cin >> n;
     for(i = 1; i <= n; i++)
     {
         cin >> k;
         in[i] += k;
         for(j = 1; j <= k; j++)
         {
             cin >> task;
             AdjList[task].push_back(i);
         }
     }
     if(TopoSort(n))
         cout << "1" << endl;
     else
         cout << "0" << endl;
    return 0;
}