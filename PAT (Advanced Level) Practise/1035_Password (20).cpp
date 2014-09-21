#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct info
{
    string name;
    string pwd;
    int ok;
    info(){ ok = 0;};
}tmp;

int main()
{
    vector<info> e;
    int n,i,j;
    while(cin >> n)
    {
        e.clear();
        int flag = 0;
        int cnt = 0;
        for(i = 0; i < n; i++)
        {
            cin >> tmp.name >> tmp.pwd;
            int ok = 0;
            for(j = 0; j < tmp.pwd.size(); j++)
            {
                if(tmp.pwd[j] == '1')   {tmp.pwd[j] = '@';   ok = 1; flag = 1;}
                if(tmp.pwd[j] == '0')   {tmp.pwd[j] = '%';   ok = 1; flag = 1;}
                if(tmp.pwd[j] == 'l')   {tmp.pwd[j] = 'L';   ok = 1; flag = 1;}
                if(tmp.pwd[j] == 'O')   {tmp.pwd[j] = 'o';   ok = 1; flag = 1;}
            }
            tmp.ok = ok;
            if(tmp.ok)  cnt++;
            e.push_back(tmp);
        }
        if(!flag)
        {
            if(e.size() == 1)   cout << "There is " << e.size() << " account and no account is modified" << endl;
            if(e.size() > 1)   cout << "There are " << e.size() << " accounts and no account is modified" << endl;
        }
        else
        {
            cout << cnt << endl;
            for(i = 0; i < e.size(); i++)
            {
                if(e[i].ok)
                {
                    cout << e[i].name << " " << e[i].pwd << endl;
                }
            }
        }
    }
    return 0;
}
