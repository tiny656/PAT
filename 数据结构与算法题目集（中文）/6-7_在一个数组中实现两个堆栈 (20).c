Stack CreateStack( int MaxSize )
{
    Stack s = (Stack) malloc(sizeof(Stack));
    s->Data = (ElementType*) malloc(sizeof(ElementType)*MaxSize);
    s->MaxSize = MaxSize;
    s->Top1 = -1;
    s->Top2 = MaxSize;
    return s;
}

bool Push( Stack S, ElementType X, int Tag )
{
    if (S == NULL) return false;
    if (S->Top1 + 1 == S->Top2) 
    {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1) S->Data[++S->Top1] = X;
    else if (Tag == 2) S->Data[--S->Top2] = X;
    return true;
}

ElementType Pop( Stack S, int Tag ) 
{
    if (S == NULL) return ERROR;

    if (Tag == 1) 
    {
        if (S->Top1 == -1) 
        {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[S->Top1--];
    }
    else 
    {
        if (S->Top2 == S->MaxSize) 
        {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[S->Top2++];
    }
}