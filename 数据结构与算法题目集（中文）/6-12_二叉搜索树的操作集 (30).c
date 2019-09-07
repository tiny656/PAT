BinTree Insert( BinTree BST, ElementType X )
{
    if (!BST) 
    {
        BST = (BinTree) malloc(sizeof(BinTree));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
        return BST;
    }
    else if (X < BST->Data) BST->Left = Insert(BST->Left, X);
    else if (X > BST->Data) BST->Right = Insert(BST->Right, X);

    return BST;
}

BinTree Delete( BinTree BST, ElementType X )
{
    if (!BST) 
    {
        printf("Not Found\n");
        return NULL;
    }

    if (X < BST->Data) BST->Left = Delete(BST->Left, X);
    else if (X > BST->Data) BST->Right = Delete(BST->Right, X);
    else 
    {
        Position t;
        if (BST->Left && BST->Right)
        {
            t = FindMin(BST->Right);
            BST->Data = t->Data;
            BST->Right = Delete(BST->Right, t->Data);
        }
        else 
        {
            t = BST;
            if (!BST->Left) BST = BST->Right;
            else if (!BST->Right) BST = BST->Left;
            free(t);
        }
    }
    return BST;
}

Position Find( BinTree BST, ElementType X )
{
    if (!BST) return NULL;
    else if (X < BST->Data) return Find(BST->Left, X);
    else if (X > BST->Data) return Find(BST->Right, X);
    else return BST;
}

Position FindMin( BinTree BST )
{
    if (!BST) return NULL;
    else if (!BST->Left) return BST;
    else return FindMin(BST->Left);
}

Position FindMax( BinTree BST )
{
    if (!BST) return NULL;
    else if (!BST->Right) return BST;
    else return FindMax(BST->Right);
}