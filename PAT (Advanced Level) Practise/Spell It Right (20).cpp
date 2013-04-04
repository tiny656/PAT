#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string map[10];

void Init()
{
    map[0] = "zero";  map[1] = "one";  map[2] = "two";   map[3] = "three";  map[4] = "four";
    map[5] = "five";  map[6] = "six";  map[7] = "seven"; map[8] = "eight";  map[9] = "nine";
}

int main()
{
    Init();
    char str[105];
    int bit[105];
    int i;
    while(cin >> str)
    {
        int ans = 0;
        for(i = 0; i < strlen(str); i++)    ans += str[i]-'0';
        int len = 0;
        if(!ans) bit[len++] = 0;
        while(ans)
        {
            bit[len++] = ans%10;
            ans/=10;
        }
        for(i = len-1; i > 0; i--)
        {
            cout << map[bit[i]] << " ";
        }
        cout << map[bit[0]] << endl;
    }
    return 0;
}
