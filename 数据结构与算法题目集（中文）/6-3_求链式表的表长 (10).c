int Length( List L ) 
{
    return L == NULL ? 0 : (1 + Length(L->Next));
}