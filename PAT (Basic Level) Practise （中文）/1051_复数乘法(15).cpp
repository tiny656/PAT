#include <bits/stdc++.h>
using namespace std;
/*
1. 实部或者虚部小于0.01时候，保留两位结果为0
2. 如果虚部为整数，添加+符号，负数为-符号
*/
int main() {
    double r[2], p[2];
    scanf("%lf%lf%lf%lf", &r[0], &p[0], &r[1], &p[1]);
    double tmp = r[0]*r[1];
    double real = tmp * cos(p[0]+p[1]);
    double complex = tmp * sin(p[0]+p[1]);
    if (fabs(real) < 0.01) real = 0;
    if (fabs(complex) < 0.01) complex = 0;
    printf("%.2f", real);
    if (complex < 0) printf("-%.2fi\n", fabs(complex));
    else printf("+%.2fi\n", complex);

    return 0;
}