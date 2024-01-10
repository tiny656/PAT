Polynomial Add( Polynomial a, Polynomial b ) {
    Polynomial head, cur;
    cur = head = a;
    a = a->Next;
    b = b->Next;
    while (a && b) {
        if (a->Exponent > b->Exponent) {
          cur->Next = a;
          a = a->Next;
          cur = cur->Next;
        } else if (a->Exponent < b->Exponent) {
          cur->Next = b;
          b = b->Next;
          cur = cur->Next;
        } else {
          if (a->Coefficient + b->Coefficient != 0) {
            cur->Next = a;
            a->Coefficient += b->Coefficient;
            cur = cur->Next;
          }
          a = a->Next;
          b = b->Next;
        }
    }
    if (a) cur->Next = a;
    else cur->Next = b;

    return head;
}