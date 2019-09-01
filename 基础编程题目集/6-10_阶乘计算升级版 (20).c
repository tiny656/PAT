void Print_Factorial ( const int N )
{
    if (N < 0) 
    {
        printf("Invalid input");
        return;
    }
    int c[20001];
    c[0] = 1;
    int digit = 1;
    for (int i = 2; i <= N; i++) 
    {
        int num = 0;
        for (int d = 0; d < digit; d++) 
        {
            num = c[d] * i + num;
            c[d] = num % 10;
            num /= 10;
        }
        while (num) 
        {
            c[digit] = num % 10;
            num /= 10;
            digit++;
        }
    }
    for (int i = digit-1; i >= 0; i--)
        printf("%d", c[i]);
}