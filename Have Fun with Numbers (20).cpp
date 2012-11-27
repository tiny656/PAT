#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int i;
    char val[25];
    while(cin >> val)
    {
        string A = "";
        int len = strlen(val);
        for(i = 0; i < len; i++)
            A += val[i];
        for(i = 0; i < len/2; i++)
        {
            char tmp = val[i];
            val[i] = val[len-i-1];
            val[len-i-1] = tmp;
        }
        for(i = len; i < 25; i++)
        {
            val[i] = '0';
        }
        int carry = 0;
        for(i = 0; i < len; i++)
        {
            int tmp = (val[i]-'0')*2 + carry;
            val[i] = tmp % 10 + '0';
            carry = tmp / 10;

        }
        if(carry)
        {
            val[i] = ((val[i]-'0')*2 + carry) % 10 + '0';
            i++;
        }
        len = i;
        string B = "";
        for(i = len-1; i >= 0; i--)
        {
            B += val[i];
        }
        if(A != B)
        {
            string tmp = B;
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());
            if(A == B)
            {
                cout << "Yes" << endl;
                cout << tmp << endl;
            }
            else
            {
                cout << "No" << endl;
                cout << tmp << endl;
            }
        }
        else
        {
            cout << "No" << endl;
            cout << B << endl;
        }
    }
    return 0;
}
