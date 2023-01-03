#include <bits/stdc++.h>
using namespace std;

// 先比较大小，然后模拟减法

// p1 - p2
void subtract(int p1[], int p2[], int ret[]) {
    for (int i = 2; i >= 0; i--) {
        if (p1[i] >= p2[i])
            ret[i] = p1[i] - p2[i];
        else {
            ret[i] = p1[i] + ((i==2) ? 29 : 17) - p2[i];
            p1[i-1]--;
        }
    }
}


int main(int argc, char const *argv[])
{
    int price1[3], price2[3];
    int remain[3];
    scanf("%d.%d.%d %d.%d.%d", &price1[0], &price1[1], &price1[2], &price2[0], &price2[1], &price2[2]);
    int big = 0;
    for (int i = 0; i < 3; i++) {
        if (price1[i] > price2[i]) {
            big = 1;
            break;
        } else if (price1[i] < price2[i]) {
            big = 2;
            break;
        } else {
            continue;
        }
    }
    if (big == 1) {
        subtract(price1, price2, remain);
        cout << "-";
    } else if (big == 2 || big == 0) subtract(price2, price1, remain);
    cout << remain[0] << "." << remain[1] << "." <<remain[2] << endl;
    return 0;
}