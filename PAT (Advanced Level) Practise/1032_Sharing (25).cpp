#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<int,int> Hash;
map<int,int> Elem;

int main()
{
    int A,B;
    int n,i;
    int s,d;
    char emp;
    scanf("%d %d %d", &A, &B, &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d %c %d", &s,&emp,&d);
        Elem[s] = d;
    }
    if(A == B)  {printf("%05d\n", A); return 0;}
    int ok = 0;
    while(A != B)
    {
        if(A == -1 || B == -1)
        {
            break;
        }
        if(Hash[A] || Hash[B])
        {
            ok = 1;
            break;
        }
        Hash[A] = Hash[B] = 1;
        A = Elem[A];
        B = Elem[B];
    }
    if(ok)
    {
        if(Hash[A]) printf("%05d\n", A);
        else    printf("%05d\n", B);
    }
    else
    {
        puts("-1");
    }
    return 0;
}
