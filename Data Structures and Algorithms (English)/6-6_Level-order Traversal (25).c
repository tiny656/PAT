void Level_order ( Tree T, void (*visit)(Tree ThisNode) ) {
  if (T == NULL) return;

  Tree queue[MaxTree+1];
  int front = 0, rear = 0;
  queue[rear++] = T;
  while (rear != front) {
    T = queue[front++];
    visit(T);
    if (T->Left != NULL) queue[rear++] = T->Left;
    if (T->Right != NULL) queue[rear++] = T->Right;
  }
}