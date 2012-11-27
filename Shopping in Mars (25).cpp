#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int e[100005];

int main()
{
    int n,key,i;
    while(scanf("%d %d", &n,&key) == 2)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d", &e[i]);
        }
        int l,r;
        l = r = 0;
        int val = e[l];
        int ok = 0;
        vector<pair<int,int> > ans;
        int min = 0x7fffffff;
        while(1)
        {
            if(val < key)
            {
                if(r+1==n)  break;
                r = r+1;
                val += e[r];
            }
            else if(val == key)
            {
                ok = 1;
                printf("%d-%d\n",l+1,r+1);
                if(r+1==n)  break;
                r = r+1;
                val += e[r];
            }
            else if(val > key)
            {
                if(val < min)
                {
                    ans.clear();
                    min = val;
                    ans.push_back(make_pair(l,r));
                }
                else if(val == min)
                {
                    ans.push_back(make_pair(l,r));
                }
                val -= e[l];
                if(l+1==n)  break;
                l = l+1;
            }
        }
        if(!ok)
        {
            for(vector<pair<int,int> >::iterator iter=ans.begin(); iter!=ans.end(); iter++)
            {
                printf("%d-%d\n",iter->first+1,iter->second+1);
            }
        }
    }
    return 0;
}
