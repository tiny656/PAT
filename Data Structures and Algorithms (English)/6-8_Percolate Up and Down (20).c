
typedef int ElementType;
#define MinData -1

typedef struct HeapStruct *PriorityQueue;
struct HeapStruct {
    ElementType  *Elements;
    int Capacity;
    int Size;
};

PriorityQueue Initialize( int MaxElements ); /* details omitted */

void PercolateUp( int p, PriorityQueue H );
void PercolateDown( int p, PriorityQueue H );

void Insert( ElementType X, PriorityQueue H ) 
{
    int p = ++H->Size;
    H->Elements[p] = X;
    PercolateUp( p, H );
}

ElementType DeleteMin( PriorityQueue H ) 
{ 
    ElementType MinElement; 
    MinElement = H->Elements[1];
    H->Elements[1] = H->Elements[H->Size--];
    PercolateDown( 1, H );
    return MinElement; 
}

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