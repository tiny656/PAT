ElementType Median(ElementType A[], int N) 
{
    ElementType aux[MAXN];
    for (int i = 0; i < N; i++) aux[i] = A[i];
    merge_help_sort(aux, A, 0, N - 1);
    return A[N/2];
}

void merge_help_sort(ElementType src[], ElementType dst[], int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + ((hi - lo) >> 1);
    merge_help_sort(dst, src, lo, mid);
    merge_help_sort(dst, src, mid + 1, hi);
    merge(src, dst, lo, mid, hi);
}

void merge(ElementType src[], ElementType dst[], int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) {
        if      (i > mid)           dst[k] = src[j++];
        else if (j > hi)            dst[k] = src[i++];
        else if (src[i] < src[j])   dst[k] = src[i++];
        else                        dst[k] = src[j++];
    }
}