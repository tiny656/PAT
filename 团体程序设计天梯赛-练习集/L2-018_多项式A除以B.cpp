#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 3000;

void Print(float c[], int maxA) {
    int tot = 0;
    for (int i = maxA; i >= 0; i--) {
        if (abs(c[i]) + 0.05f < 0.1f) continue;
        tot += 1;
    }

    printf("%d", tot);
    if (tot <= 0) printf(" 0 0.0");
    else {
        for (int i = maxA; i >= 0; i--) {
            if (abs(c[i]) + 0.05f < 0.1f) continue;
            printf(" %d %.1f", i, c[i]);
        }
    }
}

int main() {
    int n, e, maxA = 0, maxB = 0;
    float A[MAXN], B[MAXN], C[MAXN], c;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %f", &e, &c);
        if (i == 0) maxA = e;
        A[e] = c;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %f", &e, &c);
        if (i == 0) maxB = e;
        B[e] = c;
    }

    int t1 = maxA, t2 = maxB;
    while (t1 >= t2) {
        float c = A[t1] / B[t2];
        C[t1 - t2] = c;
        for (int i = t1, j = t2; j >= 0; i--, j--) A[i] -= c * B[j];
        if (abs(A[t1]) < 1e-6) t1--;
    }

    Print(C, maxA - maxB);
    printf("\n");
    Print(A, t1);
    return 0;
}