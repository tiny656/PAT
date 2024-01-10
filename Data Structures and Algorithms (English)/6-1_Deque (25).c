Deque CreateDeque() {
  Deque dq = (Deque)malloc(sizeof(struct DequeRecord));
  PtrToNode sentinel = (PtrToNode)malloc(sizeof(struct Node));

  dq -> Front = sentinel;
  dq -> Rear = sentinel;

  sentinel -> Last = NULL;
  sentinel -> Next = NULL;

  return dq;
}

int Push( ElementType X, Deque D ) {
  PtrToNode node = (PtrToNode)malloc(sizeof(struct Node));
  node -> Element = X;

  PtrToNode sentinel = D -> Front;

  node -> Last = sentinel;
  node -> Next = sentinel -> Next;

  if (D -> Front == D -> Rear) {
    sentinel -> Next = node;
    D -> Rear = node;
  } else {
    sentinel -> Next -> Last = node;
    sentinel -> Next = node;
  }

  return 1;
}

ElementType Pop( Deque D ) {
  if (D -> Front == D -> Rear) return ERROR;

  PtrToNode node = D -> Front -> Next;
  ElementType result = node -> Element;

  if (node -> Next == NULL) {
    D -> Front -> Next = NULL;
    D -> Rear = D -> Front;
  } else {
    node -> Next -> Last = D -> Front;
    D -> Front -> Next = node -> Next;
  }

  free(node);

  return result;
}

int Inject( ElementType X, Deque D ) {
  PtrToNode node = (PtrToNode)malloc(sizeof(struct Node));

  node -> Element = X;
  D -> Rear -> Next = node;
  node -> Last = D -> Rear;
  D -> Rear = node;

  return 1;
}

ElementType Eject( Deque D ) {
  if (D -> Front == D -> Rear) return ERROR;

  PtrToNode node = D -> Rear;
  ElementType result = node -> Element;

  node -> Last -> Next = NULL;
  D -> Rear = node -> Last;

  free(node);

  return result;
}