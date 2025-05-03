from collections import deque

n, m = map(int, input().split())
adj = [[] for _ in range(n)]
indeg = [0] * n
for _ in range(m):
    s, e, l = map(int, input().split())
    adj[s].append((e, l))
    indeg[e] += 1

# topological sort with max distance
q = deque(i for i in range(n) if indeg[i] == 0)
dist = [0] * n
visited = 0
while q:
    u = q.popleft()
    visited += 1
    for v, w in adj[u]:
        # 最长路径转移
        if dist[u] + w > dist[v]:
            dist[v] = dist[u] + w
        indeg[v] -= 1
        if indeg[v] == 0:
            q.append(v)

if visited != n:  # has cycle
    print("Impossible")
else:
    print(max(dist))
