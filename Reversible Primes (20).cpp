#include <iostream>
#include <cmath>
using namespace std;

bool prime(int x)
{
    if(x <= 1)  return false;
    int limit = floor(sqrt(x)+0.5);
    for(int i = 2; i <= limit; i++)
    {
        if(x%i == 0)
        {
            return false;
        }
    }
    return true;
}

int reverse(int n,int d)
{
    int bit[20];
    int len = 0;
    while(n)
    {
        bit[len++] = n%d;
        n /= d;
    }
    int res = 0;
    for(int i = 0; i < len; i++)
    {
        res = (res*d+bit[i]);
    }
    return res;
}


int main()
{
    int n,d;
    while(cin >> n, n >= 0)
    {
        cin >> d;
        if(prime(n))
        {
            int rn = reverse(n,d);
            if(prime(rn))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
