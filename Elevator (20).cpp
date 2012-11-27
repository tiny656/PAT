#include <iostream>
using namespace std;

int main()
{
    int n,tmp,i;
    while(cin >> n)
    {
        int cur = 0;
        int ans = 0;
        for(i = 0; i < n; i++)
        {
            cin >> tmp;
            ans += (tmp > cur) ? (tmp-cur)*6 : (cur-tmp)*4;
            cur = tmp;
        }
        ans += n*5;
        cout << ans << endl;
    }
    return 0;
}
