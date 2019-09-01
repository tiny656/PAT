int IsTheNumber (const int N)
{
    int n = N;
    int b = (int)sqrt(n);
    int sq = b*b == n;
    int same = 0;
    int bit[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    do {
        if (bit[n % 10] == 1) {
            same = 1;
            break;
        }
        bit[n % 10] = 1; 
        n /= 10;
    } while (n != 0);
    return sq && same;

}