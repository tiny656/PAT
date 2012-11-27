#include <iostream>
#include <cstring>
using namespace std;

bool is_Palindromic(int e[],int len)
{
    for(int i = 0; i < len/2; i++)
    {
        if(e[i] != e[len-i-1])
        {
            return false;
        }
    }
    return true;
}

void work(int n,int d)
{
    int e[1000];
    int len = 0;
    while(n)
    {
        e[len++] = n % d;
        n /= d ;

    }
    if(is_Palindromic(e,len))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    for(int i = len-1; i > 0; i--)
    {
        cout << e[i] << " ";
    }
    cout << e[0] << endl;

}


int main()
{
    int n,d;
    while(cin >> n >> d)
    {
        work(n,d);
    }
    return 0;
}
