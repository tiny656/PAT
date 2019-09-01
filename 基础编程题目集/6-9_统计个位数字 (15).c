int Count_Digit ( const int N, const int D )
{
    int n = abs(N);
    int countD = 0;
    do 
    {
        if (n % 10 == D) countD++;
        n /= 10;
    } while (n != 0);
    return countD;
}