#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string ans[55];

void Init()
{
    int len = 1,i;
    for(i = 1; i <= 9; i++,len++)
    {
        ans[len] = "  ";
        ans[len][0] = 'S';
        ans[len][1] = '0'+i;
    }
    ans[len++] = "S10";
    ans[len++] = "S11";
    ans[len++] = "S12";
    ans[len++] = "S13";
    for(i = 1; i <= 9; i++,len++)
    {
        ans[len] = "  ";
        ans[len][0] = 'H';
        ans[len][1] = '0'+i;
    }
    ans[len++] = "H10";
    ans[len++] = "H11";
    ans[len++] = "H12";
    ans[len++] = "H13";
    for(i = 1; i <= 9; i++,len++)
    {
        ans[len] = "  ";
        ans[len][0] = 'C';
        ans[len][1] = '0'+i;
    }
    ans[len++] = "C10";
    ans[len++] = "C11";
    ans[len++] = "C12";
    ans[len++] = "C13";
    for(i = 1; i <= 9; i++,len++)
    {
        ans[len] = "  ";
        ans[len][0] = 'D';
        ans[len][1] = '0'+i;
    }
    ans[len++] = "D10";
    ans[len++] = "D11";
    ans[len++] = "D12";
    ans[len++] = "D13";
    ans[len++] = "J1";
    ans[len++] = "J2";

}

int main()
{
    Init();
    int k,i,e[55];
    string tmp[55];
    while(cin >> k)
    {
        for(i = 1; i <= 54; i++)
        {
            cin >> e[i];
        }

        while(k--)
        {
            for(i = 1; i <=54; i++)
            {
                tmp[e[i]] = ans[i];
            }
            for(i = 1; i <=54; i++)
            {
                ans[i] = tmp[i];
            }
        }

        cout << ans[1];
        for(i = 2; i <=54; i++)
        {
            cout << " " << ans[i];
        }
        cout << endl;
    }
    return 0;
}
