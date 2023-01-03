#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <functional>
using namespace std;

int main()
{
    deque<int> coupon,product;
    int nc,np,val,i;
    cin >> nc;
    for(i = 0; i < nc; i++)
    {
        cin >> val;
        coupon.push_back(val);
    }
    cin >> np;
    for(i = 0; i < np; i++)
    {
        cin >> val;
        product.push_back(val);
    }
    sort(coupon.begin(), coupon.end(), greater<int>() );
    sort(product.begin(), product.end(), greater<int>() );
    int ans = 0;
    while(!coupon.empty() && !product.empty())
    {
        int a = coupon.front();
        int b = product.front();
        if(a*b >= 0)
        {
            ans += a*b;
            coupon.pop_front();
            product.pop_front();
        }
        else
        {
            break;
        }
    }
    sort(coupon.begin(), coupon.end(), less<int>() );
    sort(product.begin(), product.end(), less<int>() );
    while(!coupon.empty() && !product.empty())
    {
        int a = coupon.front();
        int b = product.front();
        if(a*b >= 0)
        {
            ans += a*b;
            coupon.pop_front();
            product.pop_front();
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
