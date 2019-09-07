List Reverse( List L )
{
    PtrToNode prev = NULL, cur = L, tmp;
    while (cur) 
    {
        tmp = cur->Next;
        cur->Next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}