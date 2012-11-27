#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int i,j;
    double ans = 1;
    double e[3];
    string w = "";
    for(i = 0; i < 3; i++)
    {
        double max = -1;
        int index;
        for(j = 0; j < 3; j++)
        {
            cin >> e[j];
            if(max < e[j])
            {
                index = j;
                max = e[j];
            }
        }
        switch(index)
        {
            case 0: w += "W "; break;
            case 1: w += "T "; break;
            case 2: w += "L "; break;
        }
        ans *= max;
    }
    cout << w;
    printf("%.2lf\n", (ans*0.65-1.0)*2.0+1e-5);

    return 0;
}
