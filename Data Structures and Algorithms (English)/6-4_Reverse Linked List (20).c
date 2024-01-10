List Reverse( List L ) {
  if (!L || !L->Next) return L;
  Position p, q, r;
  p = L->Next;
  q = p->Next;
  p->Next = NULL;
  while (q) {
      r = q->Next;
      q->Next = p;
      p = q;
      q = r;
  }
  L->Next = p;
  return L;
}