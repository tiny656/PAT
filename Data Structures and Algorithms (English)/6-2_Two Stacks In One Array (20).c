Stack CreateStack( int MaxElements ) {
  Stack stack = (Stack)malloc(sizeof(struct StackRecord));
  stack->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
  stack->Top1 = -1;
  stack->Top2 = MaxElements;
  stack->Capacity = MaxElements;
  return stack; 
}

int IsEmpty( Stack S, int Stacknum ) {
  if (Stacknum == 1) return S->Top1 == -1;
  else if (Stacknum == 2) return S->Top2 == S->Capacity;
}

int IsFull( Stack S ) {
  if (S->Top1 + 1 == S->Top2) return 1;
  else return 0;
}

int Push( ElementType X, Stack S, int Stacknum ) {
  if (IsFull(S)) return 0;
  if (Stacknum == 1) S->Array[++S->Top1] = X;
  else if (Stacknum == 2) S->Array[--S->Top2] = X;
  return 1;

}

ElementType Top_Pop( Stack S, int Stacknum ) {
  if (IsEmpty(S, Stacknum)) return ERROR;
  if (Stacknum == 1) return S->Array[S->Top1--];
  else if (Stacknum == 2) return S->Array[S->Top2++];
}