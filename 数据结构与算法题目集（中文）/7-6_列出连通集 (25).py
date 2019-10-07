def DFS(G, n):
    vis = [0] * n
    for i in xrange(n):
        result = []
        if not vis[i]:
            stack = [i]
            while len(stack) > 0:
                ele = stack[-1]
                if vis[ele] == 0:
                    vis[ele] = 1
                    result.append(ele)
                    for i in xrange(n-1, -1, -1):
                        if ele != i and vis[i] == 0 and G[ele][i] is not None:
                            stack.append(i)
                else:
                    vis[ele] = 2
                    stack.pop()
        if result: print '{ %s }' % ' '.join(map(str, result))

def BFS(G, n):
    vis = [False] * n
    for i in xrange(n):
        result = []
        if not vis[i]:
            queue = [i]
            vis[i] = True
            while len(queue) > 0:
                ele = queue.pop(0)
                result.append(ele)
                for i in xrange(n):
                    if ele != i and not vis[i] and G[ele][i] is not None:
                        queue.append(i)
                        vis[i] = True 
        if result: print '{ %s }' % ' '.join(map(str, result))


n, e = map(int, raw_input().split())
G = [[None if i!=j else 1 for i in xrange(n)] for j in xrange(n)]
for i in xrange(e):
    a, b = map(int, raw_input().split())
    G[a][b] = G[b][a] = 1
DFS(G, n)
BFS(G, n)