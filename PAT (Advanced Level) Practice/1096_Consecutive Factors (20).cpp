#include <bits/stdc++.h>
using namespace std;
// O(sqrt(n)*C)算法，枚举连续乘积
int main(int argc, char const *argv[]) {
    long long n;
    long long range = 0;
    pair<long long, long long> result;
    cin >> n;
    long long limit = (int)sqrt((double)n+0.5);
    for (long long i = 2; i <= limit; i++) {
        long long product = 1;
        for (long long j = i; j <= limit; j++) {
            product *= j;
            if (product > n) break;
            if (n % product == 0) {
                if (j-i+1 > range) {
                    range = j-i+1;
                    result = {i, j};
                }
            }
        }
    }
    if (range) {
        cout << range << endl;
        cout << result.first;
        for (int i = result.first+1; i <= result.second; i++)
            cout << "*" << i;
        cout << endl;
    } else {
        cout << 1 << endl << n <<endl;
    }
    return 0;
}