def find(parent: list[int], x: int) -> int:
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]


def union(parent: list[int], rank: list[int], a: int, b: int) -> None:
    ra, rb = find(parent, a), find(parent, b)
    if ra == rb:
        return
    if rank[ra] < rank[rb]:
        parent[ra] = rb
    elif rank[ra] > rank[rb]:
        parent[rb] = ra
    else:
        parent[rb] = ra
        rank[ra] += 1


n = int(input())

parent = list(range(n + 1))  # 1‑based
rank = [0] * (n + 1)

while True:
    op, *rest = input().split()
    if op == "S":
        break
    c1, c2 = map(int, rest)
    if op == "I":
        union(parent, rank, c1, c2)
    elif op == "C":
        print("yes" if find(parent, c1) == find(parent, c2) else "no")

# count connected components
comps = len({find(parent, i) for i in range(1, n + 1)})
if comps == 1:
    print("The network is connected.")
else:
    print(f"There are {comps} components.")
