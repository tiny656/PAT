void ShortestDist(MGraph Graph, int dist[], Vertex S) {
	bool collected[MaxVertexNum];
	int i;

	// Initialize
	for (i = 0; i < Graph->Nv; i++) {
		dist[i] = INFINITY;
		collected[i] = false;
	}
	dist[S] = 0;

	while (1) {
			// Find the uncollected vertex with smallest distance
		Vertex V = -1;
		int minDist = INFINITY;
		for (i = 0; i < Graph->Nv; i++) {
				if (collected[i] == false && dist[i] < minDist) {
						V = i;
						minDist = dist[i];
				}
		}

		// If no such vertex exists, break
		if (V == -1) break;

		collected[V] = true;

		// Update dist[] through V
		for (i = 0; i < Graph->Nv; i++) {
				if (collected[i] == false && Graph->G[V][i] > 0) {
						if (dist[V] + Graph->G[V][i] < dist[i]) {
								dist[i] = dist[V] + Graph->G[V][i];
						}
				}
		}
	}

	// Convert INFINITY to -1 for unreachable vertices
	for (i = 0; i < Graph->Nv; i++) {
		if (dist[i] == INFINITY)  dist[i] = -1;
	}
}