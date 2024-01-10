void PercolateUp( int p, PriorityQueue H ) {
  while (p > 1) {
    int parent = p / 2;
    if (H->Elements[p] < H->Elements[parent]) {
      ElementType tmp = H->Elements[p];
      H->Elements[p] = H->Elements[parent];
      H->Elements[parent] = tmp;
      p = parent;
    } else break;
  }
}

void PercolateDown( int p, PriorityQueue H ) {
  while (p * 2 <= H->Size) {
    int child = p * 2;
    if (child + 1 <= H->Size && H->Elements[child + 1] < H->Elements[child]) child++;
    if (H->Elements[p] > H->Elements[child]) {
      ElementType tmp = H->Elements[p];
      H->Elements[p] = H->Elements[child];
      H->Elements[child] = tmp;
      p = child;
    } else break;
  }
}