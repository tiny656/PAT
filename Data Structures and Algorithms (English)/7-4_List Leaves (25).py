n = int(input().strip())
nodes = [tuple(int(x) if x != "-" else -1 for x in input().split()) for _ in range(n)]
is_root = [True] * n
for i, (l, r) in enumerate(nodes):
    if l != -1:
        is_root[l] = False
    if r != -1:
        is_root[r] = False

root = is_root.index(True)
leaves = []
q = [root]
while q:
    u = q.pop(0)
    l, r = nodes[u]
    if l == r == -1:
        leaves.append(u)
    if l != -1:
        q.append(l)
    if r != -1:
        q.append(r)

print(*leaves)
