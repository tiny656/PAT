Position Find( List L, ElementType X )
{
    while (L != NULL && L->Data != X) L = L->Next;
    return L != NULL ? L : ERROR;
}

List Insert( List L, ElementType X, Position P ) 
{
    PtrToLNode newNode = (PtrToLNode)malloc(sizeof(PtrToLNode));
    newNode->Data = X;
    newNode->Next = NULL;

    if (L == NULL) return newNode;

    List q = L;
    PtrToLNode prev = NULL;
    while (q != NULL && q != P)
    {
        prev = q;
        q = q->Next;
    } 

    if (q == NULL && P != NULL)
    {
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }

    newNode->Next = q;
    if (prev == NULL) 
    {
        return newNode;
    }
    else 
    {
        prev->Next = newNode;
        return L;
    }
}

List Delete( List L, Position P ) 
{
    List q = L;
    PtrToLNode prev = NULL;
    while (q != NULL && q != P)
    {
        prev = q;
        q = q->Next;
    } 
    if (q == NULL)
    {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    if (prev == NULL) 
    {
        PtrToLNode result = q->Next;
        q->Next = NULL;
        return result;
    }
    else 
    {
        prev->Next = q->Next;
        return L;
    }
}