ElementType Max(ElementType S[],int N) 
{
    ElementType result = S[0];
    for (int i = 1; i < N; i++) 
    {
        result = S[i] > result ? S[i] : result;
    }
    return result;
}