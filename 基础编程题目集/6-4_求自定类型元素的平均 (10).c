ElementType Average(ElementType S[], int N) 
{
    ElementType sum = 0;
    for (int i = 0; i < N; i++) 
    {
        sum += S[i];
    }
    return sum / N;
}