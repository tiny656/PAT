#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
using namespace std;
/*
排序加二分 
*/
struct e
{
    int glod,tot;
    double avg_gold,avg_tot;	
}info[225];

int a[225];
int b[225];
double c[225];
double d[225];
vector<pair<int,int> > ans; 

template <class T>
int find(T v, T elem[], int l, int r)
{
    int left = l, right = r-1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if(elem[mid] == v)
        {
            while(mid >= 0 && elem[mid] == v)
                mid--;
            mid++;
            return mid;
        }	
        else if(elem[mid] < v) right = mid - 1;
        else left = mid + 1;
    }
}

int main()
{
    int i,n,ask,gold,tot,peo,cur;
    scanf("%d %d", &n,&ask);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &gold, &tot, &peo);
        info[i].glod = gold;
        info[i].tot = tot;
        info[i].avg_gold = (double)gold/(double)peo;
        info[i].avg_tot = (double)tot/(double)peo;			
        a[i] = gold;
        b[i] = tot;
        c[i] = (double)gold/(double)peo;
        d[i] = (double)tot/(double)peo;
    }
    sort(a,a+n,greater<int>());	
    sort(b,b+n,greater<int>());
    sort(c,c+n,greater<double>());
    sort(d,d+n,greater<double>());
        
    int tmp1,tmp2, tmp3, tmp4; 

    for(i = 1; i <= ask; i++)
    {
        scanf("%d", &cur);
        tmp1 = find(info[cur].glod, a, 0, n);
        if(tmp1 == 0)
        {
            ans.push_back(make_pair(0,1));
            continue;
        }
        tmp2 = find(info[cur].tot, b, 0, n);
        if(tmp2 == 0)
        {
            ans.push_back(make_pair(0,2));
            continue;
        }
        tmp3 = find(info[cur].avg_gold, c, 0, n);
        if(tmp3 == 0)
        {
            ans.push_back(make_pair(0,3));
            continue;
        }
        tmp4 = find(info[cur].avg_tot, d, 0, n);
        if(tmp4 == 0)
        {
            ans.push_back(make_pair(0,4));
            continue;
        }
        int tmptmp = min(min(min(tmp1,tmp2),tmp3),tmp4);
        if(tmp1 == tmptmp)
            ans.push_back(make_pair(tmptmp,1));
        else if(tmp2 == tmptmp)
            ans.push_back(make_pair(tmptmp,2));
        else if(tmp3 == tmptmp)
            ans.push_back(make_pair(tmptmp,3));
        else if(tmp4 == tmptmp)
            ans.push_back(make_pair(tmptmp,4));
        
    }
    printf("%d:%d", ans[0].first+1, ans[0].second );
    for(i = 1; i < ans.size(); i++)
    {
        printf(" %d:%d", ans[i].first+1, ans[i].second );
    }
    printf("\n");
    return 0;
}