// Helper structure to store DFS information for each vertex
typedef struct {
	int dfn;           // Discovery time
	int low;           // Lowest vertex reachable
	int inStack;       // Whether vertex is in stack
} VertexInfo;

// Helper function for Tarjan's algorithm
void Tarjan(Graph G, Vertex v, VertexInfo *info, Vertex *stack, int *top,
					int *time, void (*visit)(Vertex), int *visited) {
	info[v].dfn = info[v].low = (*time)++;
	stack[(*top)++] = v;
	info[v].inStack = 1;

	PtrToVNode node = G->Array[v];
	while (node) {
			Vertex w = node->Vert;
			if (info[w].dfn == -1) {  // Unvisited vertex
					Tarjan(G, w, info, stack, top, time, visit, visited);
					if (info[w].low < info[v].low)
							info[v].low = info[w].low;
			} else if (info[w].inStack) {  // Back edge to vertex in stack
					if (info[w].dfn < info[v].low)
							info[v].low = info[w].dfn;
			}
			node = node->Next;
	}

	// If v is root of SCC, pop stack and print component
	if (info[v].dfn == info[v].low) {
			Vertex w;
			do {
					w = stack[--(*top)];
					info[w].inStack = 0;
					if (!visited[w]) {
							(*visit)(w);
							visited[w] = 1;
					}
			} while (w != v);
			printf("\n");  // Print newline after each component
	}
}

void StronglyConnectedComponents(Graph G, void (*visit)(Vertex V)) {
	// Initialize arrays
	VertexInfo *info = (VertexInfo*)malloc(G->NumOfVertices * sizeof(VertexInfo));
	Vertex *stack = (Vertex*)malloc(G->NumOfVertices * sizeof(Vertex));
	int *visited = (int*)calloc(G->NumOfVertices, sizeof(int));
	int top = 0;   // Stack top
	int time = 0;  // DFS timestamp

	// Initialize vertex info
	for (Vertex v = 0; v < G->NumOfVertices; v++) {
			info[v].dfn = -1;
			info[v].low = -1;
			info[v].inStack = 0;
	}

	// Run Tarjan's algorithm for each unvisited vertex
	for (Vertex v = 0; v < G->NumOfVertices; v++) {
			if (info[v].dfn == -1) {
					Tarjan(G, v, info, stack, &top, &time, visit, visited);
			}
	}

	// Free memory
	free(info);
	free(stack);
	free(visited);
}