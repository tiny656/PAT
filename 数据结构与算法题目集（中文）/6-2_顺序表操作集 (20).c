List MakeEmpty() 
{
    List L = (List) malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

Position Find( List L, ElementType X ) 
{
    for (Position i = 0; i <= L->Last; i++) {
        if (X == L->Data[i]) return i;
    }
    return ERROR;
}

bool Insert( List L, ElementType X, Position P ) 
{
    if (L->Last + 1 == MAXSIZE) 
    {
        printf("FULL");
        return false;
    }
    if (P < 0 || P > L-> Last+1) 
    {
        printf("ILLEGAL POSITION");
        return false;
    }
    for (Position i = L->Last; i >= P; i--) 
    {
        L->Data[i+1] = L->Data[i];
    }
    L->Data[P] = X;
    L->Last += 1;
    return true;
}

bool Delete( List L, Position P ) 
{
    if (P < 0 || P > L-> Last) 
    {
        printf("POSITION %d EMPTY", P);
        return false;
    }
    for (Position i = P; i < L->Last; i++) 
    {
        L->Data[i] = L->Data[i+1];
    }
    L->Last -= 1;
    return true;
}