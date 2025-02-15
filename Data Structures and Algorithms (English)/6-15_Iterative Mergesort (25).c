void merge_pass(ElementType list[], ElementType sorted[], int N, int length) {
  int i, j, k, a, b;
  int start1, end1, start2, end2;

  // Process pairs of sublists
  for (i = 0; i < N; i += 2 * length) {
    // Define boundaries for first sublist
    start1 = i;
    end1 = start1 + length < N ? start1 + length : N;

    // Define boundaries for second sublist
    start2 = end1;
    end2 = start2 + length < N ? start2 + length : N;

    // Merge the two sublists
    k = start1;  // Starting position in sorted array
    a = start1;  // Index for first sublist
    b = start2;  // Index for second sublist

    // Compare and merge elements from both sublists
    while (1)
    {
      if      (a == end1 && b == end2)  break;
      else if (a == end1)               sorted[k++] = list[b++];
      else if (b == end2)               sorted[k++] = list[a++];
      else if (list[a] <= list[b])      sorted[k++] = list[a++];
      else                              sorted[k++] = list[b++];
    }
  }
}