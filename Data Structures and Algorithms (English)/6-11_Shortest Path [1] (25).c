void ShortestDist(LGraph Graph, int dist[], Vertex S) {
	// Initialize queue for BFS
	int queue[MaxVertexNum];
	int front = 0, rear = 0;
	bool visited[MaxVertexNum] = {false};

	// Initialize all distances to -1 (unreachable)
	for (int i = 0; i < Graph->Nv; i++) {
			dist[i] = -1;
	}

	// Set distance to source as 0 and enqueue
	dist[S] = 0;
	queue[rear++] = S;
	visited[S] = true;

	// BFS
	while (front < rear) {
		// Dequeue a vertex
		Vertex V = queue[front++];

		// Traverse all adjacent vertices
		PtrToAdjVNode currentNode = Graph->G[V].FirstEdge;
		while (currentNode) {
				Vertex W = currentNode->AdjV;
				if (!visited[W]) {
						// Update distance and enqueue
						dist[W] = dist[V] + 1;
						queue[rear++] = W;
						visited[W] = true;
				}
				currentNode = currentNode->Next;
		}
	}
}