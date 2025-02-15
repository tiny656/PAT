bool TopSort(LGraph Graph, Vertex TopOrder[]) {
	int inDegree[MaxVertexNum] = {0};  // Array to store in-degree of each vertex
	int count = 0;                      // Count of vertices in topological order
	Vertex queue[MaxVertexNum];         // Queue to store vertices with 0 in-degree
	int front = 0, rear = 0;           // Queue pointers

	// Calculate in-degree for each vertex
	for (int v = 0; v < Graph->Nv; v++) {
		PtrToAdjVNode w = Graph->G[v].FirstEdge;
		while (w) {
				inDegree[w->AdjV]++;
				w = w->Next;
		}
	}

	// Initialize queue with vertices that have 0 in-degree
	for (int v = 0; v < Graph->Nv; v++) {
		if (inDegree[v] == 0) {
				queue[rear++] = v;
		}
	}

	// Process vertices in queue
	while (front < rear) {
		Vertex v = queue[front++];
		TopOrder[count++] = v;

		// Decrease in-degree for all adjacent vertices
		PtrToAdjVNode w = Graph->G[v].FirstEdge;
		while (w) {
			if (--inDegree[w->AdjV] == 0) {
					queue[rear++] = w->AdjV;
			}
			w = w->Next;
		}
	}

	// If count equals number of vertices, topological sort is possible
	return count == Graph->Nv;
}