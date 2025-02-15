void ShortestDist(MGraph Graph, int dist[], int count[], Vertex S) {
	int i;
	bool collected[MaxVertexNum];

	// Initialize
	for (i = 0; i < Graph->Nv; i++) {
		dist[i] = INFINITY;
		count[i] = 0;
		collected[i] = false;
	}

	// Initialize source vertex
	dist[S] = 0;
	count[S] = 1;

	while (1) {
		// Find the uncollected vertex with minimum distance
		int minV = -1;
		int minDist = INFINITY;
		for (i = 0; i < Graph->Nv; i++) {
			if (!collected[i] && dist[i] < minDist) {
				minDist = dist[i];
				minV = i;
			}
		}

		// If no such vertex exists, break
		if (minV == -1) break;

		collected[minV] = true;
		// Update dist[] and count[] through minV
		for (i = 0; i < Graph->Nv; i++) {
			if (!collected[i] && Graph->G[minV][i] < INFINITY) {
					if (dist[minV] + Graph->G[minV][i] < dist[i]) {
						// Found a shorter path
						dist[i] = dist[minV] + Graph->G[minV][i];
						count[i] = count[minV];
					}
					else if (dist[minV] + Graph->G[minV][i] == dist[i]) {
						// Found another shortest path
						count[i] += count[minV];
					}
			}
		}
	}

	// Convert unreachable vertices' distance to -1
	for (i = 0; i < Graph->Nv; i++) {
		if (dist[i] == INFINITY) {
			dist[i] = -1;
			count[i] = 0;
		}
	}
}