#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(const string &a, const string &b)
{
    string c = a+b;
    string d = b+a;

    while(c[0] == '0' && c.size() >= 1)
    {
        c = c.substr(1, c.size());
    }
    while(d[0] == '0' && d.size() >= 1)
    {
        d = d.substr(1, d.size());
    }

    if(c.size() == d.size())
        return c < d;
    return c.size() < d.size();
}
vector<string> e;

int main()
{
    int n,i;
    string str;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> str;
        string tmp = str;
        while(str[0] == '0' && str.size() >= 1)
        {
            str = str.substr(1,str.size());
        }
        if(str == "")   continue;
        e.push_back(tmp);
    }
    sort(e.begin(), e.end(), cmp);
    string ans = "";
    for(i = 0; i < e.size(); i++)
        ans += e[i];
    while(ans[0] == '0' && ans.size() >= 1)
    {
        ans = ans.substr(1,ans.size());
    }
    if(ans == "")   ans = "0";
    cout << ans << endl;
    return 0;
}
