void InorderTraversal( BinTree BT )
{
    if (BT == NULL) return;
    InorderTraversal(BT->Left);
    printf(" %c", BT->Data);
    InorderTraversal(BT->Right);

}
void PreorderTraversal( BinTree BT )
{
    if (BT == NULL) return;
    printf(" %c", BT->Data);
    PreorderTraversal(BT->Left);
    PreorderTraversal(BT->Right);
}

void PostorderTraversal( BinTree BT ) 
{
    if (BT == NULL) return;
    PostorderTraversal(BT->Left);
    PostorderTraversal(BT->Right);
    printf(" %c", BT->Data);
}

void LevelorderTraversal( BinTree BT )
{
    if (BT == NULL) return;
    Position q[1000];
    int head = 0, rear = 0;
    q[rear++] = BT;
    while (head < rear) 
    {
        Position p = q[head++];
        printf(" %c", p->Data);
        if (p->Left) q[rear++] = p->Left;
        if (p->Right) q[rear++] = p->Right;
    }
}