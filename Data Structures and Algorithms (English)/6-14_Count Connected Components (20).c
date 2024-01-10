typedef enum {false, true} bool;
#define MaxVertexNum 10  /* maximum number of vertices */
typedef int Vertex;      /* vertices are numbered from 0 to MaxVertexNum-1 */

typedef struct AdjVNode *PtrToAdjVNode; 
struct AdjVNode{
    Vertex AdjV;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
} AdjList[MaxVertexNum];

typedef struct GNode *PtrToGNode;
struct GNode{  
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

int CountConnectedComponents( LGraph Graph ) {
    int count = 0;
    bool visited[MaxVertexNum];
    int queue[MaxVertexNum];
    int front = 0, rear = 0;
    for (int i = 0; i < Graph->Nv; i++) visited[i] = false;
    for (int i = 0; i < Graph->Nv; i++) {
      if (visited[i] == true)  continue;
      count++;
      visited[i] = true;
      queue[rear++] = i;
      while (front != rear) {
          int v = queue[front++];
          PtrToAdjVNode p = Graph->G[v].FirstEdge;
          while (p) {
              if (visited[p->AdjV] == false) {
                  visited[p->AdjV] = true;
                  queue[rear++] = p->AdjV;
              }
              p = p->Next;
          }
      }
    }
    return count;
}