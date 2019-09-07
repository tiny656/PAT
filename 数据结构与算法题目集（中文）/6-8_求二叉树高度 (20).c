int max(int a, int b) 
{
    return a > b ? a : b;
}

int GetHeight( BinTree BT ) 
{
    return BT == NULL ? 0 : (max(GetHeight(BT->Left), GetHeight(BT->Right)) + 1);
}