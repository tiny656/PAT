#include <iostream>
#include <vector>
using namespace std;

/*
令
$ S=a_0,a_1,...,a_i,...,a_j,...,a_{n-1},a_n $ 的逆序数
$ S'=a_0,a_1,...,a_j,...,a_i,...,a_{n-1},a_n $ 的逆序数
$ X=a_i,...,a_j $ 的逆序数
$ X'=a_j,...,a_i $ 的逆序数
把$S$拆分成三部分来分析
$a_0,a_1,...$
$a_i,...,a_j$
$...,a_{n-1},a_n$
将$S$变成$S'$,第一部分和第三部分对应的逆序数是不受影响，总体的逆序数变化为$X-X'$
所以$S'=S-(X-X')$
因为$X+X'=\frac {(j-i+1)\times(j-i)} {2}$
所以$S'=S-2*X+\frac {(j-i+1)\times(j-i)} {2}$
*/
int main() {
    ios::sync_with_stdio(false);
    int n, v, tot = 0;
    vector<int> arr, reverse;

    cin >> n;
    arr.resize(n);
    reverse.resize(n*n, 0);

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i; j < n; j++) {
            if (arr[i] > arr[j]) s++;
            reverse[i*n+j] = s; 
        }
        tot += s;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int t = 0;
            for (int k = i; k < j; k++) t += reverse[k*n+j];
            int ans = tot - 2*t + (j-i+1)*(j-i)/2;
            if (i == 0 && j == 0) cout << ans;
            else cout << " " << ans;
        }
    }
    return 0;
}
