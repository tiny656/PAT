/*
Suppose you have an array of N elements, containing three distinct keys, "true", "false", and "maybe". Given an O(N) algorithm to rearrange the list so that all "false" elements precede "maybe" elements, which in turn precede "true" elements. You may use only constant extra space.
*/
void MySort( ElementType A[], int N ) {
  int falseCount = 0, maybeCount = 0, trueCount = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == false) falseCount++;
    else if (A[i] == maybe) maybeCount++;
    else trueCount++;
  }
  for (int i = 0; i < falseCount; i++) A[i] = false;
  for (int i = falseCount; i < falseCount + maybeCount; i++) A[i] = maybe;
  for (int i = falseCount + maybeCount; i < N; i++) A[i] = true;
}