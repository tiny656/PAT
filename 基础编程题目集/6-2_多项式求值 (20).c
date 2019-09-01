double f(int n, double a[], double x) 
{
    double sum = 0;
    double base = 1;
    for (int i = 0; i <= n; i++) {
        sum += a[i] * base;
        base *= x;
    }
    return sum;
}