#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
using namespace std;


string convert(int x)
{
    string ans = "";
    while(x)
    {
        switch(x%13)
        {
            case 10: ans += 'A'; break;
            case 11: ans += 'B'; break;
            case 12: ans += 'C'; break;
            default: ans += (x%13+'0');
        }
        x /= 13;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int a,b,c;
    while(cin >> a >> b >> c)
    {
        cout << "#" << setfill('0') << setw(2) << convert(a) << setw(2) << convert(b) << setw(2) << convert(c) << endl;
    }
    return 0;
}
