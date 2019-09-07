ElementType FindKth( List L, int K ) 
{
    int cnt = 1;
    while (cnt != K && L != NULL) 
    {
        cnt++;
        L = L->Next;
    }
    return (cnt == K && L != NULL) ? L->Data : ERROR; 
}