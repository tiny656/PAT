List MakeEmpty() 
{
    return (List) malloc(sizeof(struct LNode));
}

Position Find( List L, ElementType X )
{
    L = L->Next;
    while (L != NULL && L->Data != X) L = L->Next;
    return L != NULL ? L : ERROR;
}

bool Insert( List L, ElementType X, Position P ) 
{
    PtrToLNode newNode = (PtrToLNode) malloc(sizeof(PtrToLNode));
    newNode->Data = X;
    newNode->Next = NULL;

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
        return false;
    }

    newNode->Next = q;
    if (prev != NULL) 
    {
        prev->Next = newNode;
    }
    return true;
}

bool Delete( List L, Position P ) 
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
        return false;
    }
    if (prev == NULL) 
    {
        q->Next = NULL;
    }
    else 
    {
        prev->Next = q->Next;
    }
    return true;
}