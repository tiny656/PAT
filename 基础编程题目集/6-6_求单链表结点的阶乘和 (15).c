int FactorialSum( List L ) 
{
    int sum = 0;
    while (L != NULL) 
    {
        int fac = 1;
        for (int i = L->Data; i >= 2; i--) 
        {
            fac *= i;
        }
        sum += fac;
        L = L->Next;
    }   
    return sum; 
}