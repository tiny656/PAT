void ShortestDist(MGraph Graph, int dist[], int path[], Vertex S) {
    bool collected[MaxVertexNum];
    int V, W, minV;
    WeightType minDist;

    // Initialize
    for (V = 0; V < Graph->Nv; V++) {
        dist[V] = INFINITY;
        path[V] = -1;
        collected[V] = false;
    }

    // Set source vertex
    dist[S] = 0;

    while (1) {
        // Find the uncollected vertex with minimum distance
        minDist = INFINITY;
        minV = -1;

        for (V = 0; V < Graph->Nv; V++) {
            if (collected[V] == false && dist[V] < minDist) {
                minDist = dist[V];
                minV = V;
            }
        }

        // If no such vertex exists, break
        if (minV == -1) break;

        collected[minV] = true;

        // Update dist[] and path[] through minV
        for (W = 0; W < Graph->Nv; W++) {
            if (collected[W] == false && Graph->G[minV][W] < INFINITY) {
                if (dist[minV] + Graph->G[minV][W] < dist[W]) {
                    dist[W] = dist[minV] + Graph->G[minV][W];
                    path[W] = minV;
                } else if (dist[minV] + Graph->G[minV][W] == dist[W] &&
                         GetPathLength(path, minV, S) + 1 < GetPathLength(path, W, S)) {
                    // If same distance but fewer edges, update path
                    path[W] = minV;
                }
            }
        }
    }

    // Convert unreachable vertices' distances to -1
    for (V = 0; V < Graph->Nv; V++) {
        if (dist[V] == INFINITY) {
            dist[V] = -1;
        }
    }
}

// Helper function to count the number of edges in a path
int GetPathLength(int path[], int V, int S) {
    int count = 0;
    while (V != S && V != -1) {
        count++;
        V = path[V];
    }
    return V == -1 ? INFINITY : count;
}