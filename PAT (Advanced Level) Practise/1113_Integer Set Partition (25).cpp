/*
排序，平分大端的和减去小端的和，注意偶数个数量之差为0，奇数个数量之差为1
*/
#include <bits/stdc++.h>
using namespace std;

int arr[100005];

int main () {
    int n, sum = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sort(arr, arr+n);
    int s1 = 0;
    for (int i = 0; i < n/2; i++)
        s1 += arr[i];
    printf("%d %d\n", n%2, (sum - 2*s1));
    return 0;
}