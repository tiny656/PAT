int  Search_Bin(SSTable T, KeyType k) 
{
    int lo = 1, hi = T.length;
    while (lo < hi) 
    {
        int mid = lo + (hi-lo) / 2;
        if (T.R[mid].key == k) return mid;
        else if (T.R[mid].key < k) lo = mid+1;
        else hi = mid-1;
    }
    return 0;
}