int Factorial( const int N ) 
{
    int result = 1;
    for (int i = 2; i <= N; i++) 
    {
        result *= i;
    }
    return N >= 0 ? result : 0;
}