//第七组样例超时
//1、需要二分答案....
//2、结果用long long


#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;


long long val['z'+1];

long long rBaseToDec(long long p[],long long len, long long radix)
{
    long long m = 1;
    long long num = 1;
    long long sum = 0;
    for(long long i=len-1;i>=0;i--)
    {
        sum += p[i]*m;
        m *= radix;
    }
    return sum;
}

void Init()
{
    long long i;
    for(i = '0'; i <= '9'; i++)
    {
        val[i] = i-'0';
    }
    for(i = 'a'; i <= 'z'; i++)
    {
        val[i] = i-'a'+10;
    }
}

int compare(long long  p[],long long len,long long radix ,long long target)
{
    long long m = 1;
    long long num = 1;
    long long sum = 0;
    for(long long i = len-1; i >= 0; i--)
    {
        sum += p[i]*m;
        m *= radix;
        if(sum > target)  //avoid  overflow
            return 1;
    }
    if(sum > target)
        return 1;
    else if(sum < target)
        return -1;
    else
        return 0;
}

long long binarySearch(long long p[],long long n,long long low,long long high,long long key)
{
    long long mid = low;
    long long tmp;

    while(low <= high)
    {
        tmp = compare(p, n, mid, key);
        if(tmp > 0)
        {
            high = mid - 1;
        }
        else if(tmp < 0)
        {
            low = mid +1;
        }
        else   return mid;
        mid = (low + high) >> 1;
    }
    return -1;
}

int main()
{
    string n1,n2;
    long long N1[15],N2[15],lenN1,lenN2;
    long long i,tag,radix;
    Init();
    while(cin >> n1 >> n2 >> tag >> radix)
    {
        if(tag == 2)
        {
            string tmp = n1;
            n1 = n2;
            n2 = tmp;
        }

        for(i = 0; i < n1.size(); i++)
        {
            N1[i] = val[n1[i]];
        }
        lenN1 = n1.size();

        long long max = 0;
        for(i = 0; i < n2.size(); i++)
        {
            N2[i] = val[n2[i]];
            if(N2[i]+1 > max)
                max = N2[i]+1;
        }
        lenN2 = n2.size();

        long long defVal = rBaseToDec(N1, lenN1, radix);

        long long low = max;
        long long high = (defVal+1 > max+1) ? defVal+1 : max+1;
        long long res = binarySearch(N2, lenN2, low, high, defVal);

        if(res == -1)
            cout<< "Impossible" <<endl;
        else
            cout<< res <<endl;


    }
    return 0;
}
