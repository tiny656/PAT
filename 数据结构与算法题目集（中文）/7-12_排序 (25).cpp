#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005];

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    printf("%d", arr[0]);
    for (int i = 1; i < n; i++) printf(" %d", arr[i]);
    printf("\n");
    return 0;
}
