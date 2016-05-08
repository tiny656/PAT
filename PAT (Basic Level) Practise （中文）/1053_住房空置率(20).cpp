#include <bits/stdc++.h>
using namespace std;

/*
1. 超过一半日子电量低于阈值e，可能空置
2. 满足上一条，观察期天数超过阈值D天，为空置
*/
int main() {
    int n, d, k;
    double e, ce;
    cin >> n >> e >> d;
    int tot = n;
    int mayEmpty = 0, empty = 0;
    while (n--) {
        cin >> k;
        int watch = 0;
        for (int i = 0; i < k; i++) {
            cin >> ce;
            if (ce < e) watch++;
        }
        if ((double)watch > (double)k / 2.0) {
            if (k > d) empty++;
            else mayEmpty++;
        }
    }
    cout << setiosflags(ios::fixed) << setprecision(1) << (double)mayEmpty*100.0/tot << "% " << (double)empty*100.0/tot << "%" << endl;
    return 0;
}
