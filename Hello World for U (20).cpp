#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n1,n2,N,l,r,j,i;
    N = str.size();
    for(n1 = N; ; n1--)
    {
        n2 = N+2-2*n1;
        if(n2 >= 3 && n2 <= N && n1 <= n2)  break;
    }
    int space = n2-2;
    int times = n1-1;
    for(l = 0, r = N-1; times-- ;l++,r--)
    {
        cout << str[l];
        for(i = 1; i <= space; i++) cout << " ";
        cout << str[r] << endl;
    }
    for(i = l; i <= r; i++)
        cout << str[i];
    cout << endl;
    return 0;
}
