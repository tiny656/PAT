//对于两个有序数组，归并排序的思想，找出第(n1+n2)/2的位置的数。O(m+n)的算法复杂度
#include <cstdio>
#include <vector>
using namespace std;

vector<int> store1;
vector<int> store2;

int main()
{
    int n1,n2,i,c;
    scanf("%d",&n1);
    for(i = 1; i <= n1; i++)
    {
        scanf("%d",&c);
        store1.push_back(c);
    }
    scanf("%d",&n2);
    for(i = 1; i <= n2; i++)
    {
        scanf("%d",&c);
        store2.push_back(c);
    }
    int pos = (n1+n2+1)/2;
    int cur = 0;
    int p1,p2,ans;
    p1 = p2 = 0;
    while(cur != pos)
    {
        while(p1 < n1 && store1[p1] <= store2[p2] && cur != pos)
        {
            ans = store1[p1];
            p1++;
            cur++;
        }
        if(p1 >= n1)    break;
        while(p2 < n2 && store1[p1] > store2[p2] && cur != pos)
        {
            ans = store2[p2];
            p2++;
            cur++;
        }
        if(p2 >= n2)    break;
    }
    if(cur != pos)
    {
        while(p1 < n1 && cur != pos)
        {
            ans = store1[p1];
            p1++;
            cur++;
        }
        while(p2 < n2 && cur != pos)
        {
            ans = store2[p2];
            p2++;
            cur++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
