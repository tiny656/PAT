#include <bits/stdc++.h>
using namespace std;

// 先判断是否是堆排序，
// 如果是堆排序，再进行一次sink操作
// 如果是插入排序，再进行一次插入
int ori[105], mid_sort[105];
int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ori[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &mid_sort[i]);
    }
    int pos = 1;
    sort(ori+1, ori+n+1);
    for (int i = n; i >= 1; i--) {
        if (ori[i] != mid_sort[i]) {
            pos = i;
            break;
        }
    }
    if (pos == n) {
        for (int i = 1; i < n; i++) {
            if (mid_sort[i] > mid_sort[i+1]) {
                pos = i;
                break;
            }
        }
        puts("Insertion Sort");
        for (int i = 1; i <= pos+1; i++) {
            int j = i-1;
            int minVal = mid_sort[i];
            for (j = i-1; j >= 1 && mid_sort[j] > minVal; j--) {
                mid_sort[j+1] = mid_sort[j];
            }
            mid_sort[j+1] = minVal;
        }
        printf("%d", mid_sort[1]);
        for (int i = 2; i <= n; i++)
            printf(" %d", mid_sort[i]);
        puts("");
    } else {
        printf("Heap Sort\n");
        swap (mid_sort[1], mid_sort[pos]);
        int k = 1;
        while (2*k <= pos-1) {
          int j = 2*k;
          if (j < pos-1 && mid_sort[j] < mid_sort[j+1]) j++;
          if (mid_sort[k] >= mid_sort[j]) break;
          swap(mid_sort[k], mid_sort[j]);
          k = j;
        }
        printf("%d", mid_sort[1]);
        for (int i = 2; i <= n; i++)
            printf(" %d", mid_sort[i]);
        puts("");
    }
    return 0;
}

/*
Sample Input 1:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
Sample Output 1:
Insertion Sort
1 2 3 5 7 8 9 4 6 0
Sample Input 2:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
Sample Output 2:
Heap Sort
5 4 3 1 0 2 6 7 8 9
 */