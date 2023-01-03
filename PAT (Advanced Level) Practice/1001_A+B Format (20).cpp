#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a, b,i,j;
    while(cin >> a >> b)
    {
        int c = a+b;
        int tmp[25];
        char ans[25];
        int len = 0;
        if(c == 0) tmp[len++] = 0;
        int v = 1;
        if(c < 0) { v = 0; c*= -1;}
        while(c)
        {
            tmp[len++] = c%10;
            c/=10;
        }
        int cnt = 0;
        for(i = 0,j = 0; i < len; i++)
        {
            ans[j++] = tmp[i]+'0';
            cnt++;
            if(cnt == 3)
            {
                ans[j++] = ',';
                cnt = 0;
            }
        }
        if(!v) ans[j++] = '-';
        for(i = j-1; i >= 0; i--)
        {
            if(i == j-1 && ans[j-1] == ',') continue;
            if(ans[i] == ',' && ans[i+1] == '-') continue;
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
