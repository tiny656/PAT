Position BinarySearch( List L, ElementType X )
{
    Position lo = 1, hi = L->Last;
    while (lo <= hi) 
    {
        Position mid = lo + ((hi-lo)>>1);
        if (L->Data[mid] == X) return mid;
        else if (L->Data[mid] > X) hi = mid-1;
        else lo = mid+1;
    }
    return NotFound;
}