#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
/*
贪心算法  正数*正数  负数*负数 
*/
int main()
{
    deque<int> A,B;
    int m,n,i,e;
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> e;
        A.push_back(e);	
    }
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> e;
        B.push_back(e);	
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans = 0;
    while(!A.empty() && !B.empty() && A.back() > 0 && B.back() > 0)
    {
        ans += A.back()*B.back();
        A.pop_back();
        B.pop_back();
    }
    while(!A.empty() && !B.empty() && A.front() < 0 && B.front() < 0)
    {
        ans += A.front()*B.front();
        A.pop_front();
        B.pop_front();
    }
    cout << ans << endl;
    return 0;	
}