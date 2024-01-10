int Isomorphic( Tree T1, Tree T2 ) {
  return 
         (T1 == NULL && T2 == NULL) || (
         T1 != NULL && T2 != NULL &&
         T1->Element == T2->Element && 
         ((Isomorphic(T1->Left, T2->Left) && Isomorphic(T1->Right, T2->Right))
         || (Isomorphic(T1->Left, T2->Right) && Isomorphic(T1->Right, T2->Left))));
}