#include <bits/stdc++.h>
using namespace std;
// 位运算，r表示该列的禁位，ld和rd表示当前列对角线的禁位
int main() {
    int K, N, q;
    bitset<1000> ld, rd, r;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &N);
        ld.reset(); rd.reset(); r.reset();
        bool ok = true;
        for (int j = 0; j < N; j++) {
            scanf("%d", &q);
            if (!ok) continue;
            if (ld.test(q-1) or rd.test(q-1) or r.test(q-1)) ok = false;
            else {
                ld.set(q-1); rd.set(q-1);
                ld <<= 1; rd >>= 1;
                r.set(q-1);
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
