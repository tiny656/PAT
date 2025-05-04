import heapq


def reconstruct(seq, n):
    adj: dict[int, set[int]] = {}
    indeg: dict[int, int] = {}
    keys = [x for x in seq if x >= 0]

    # build graph
    for pos, x in enumerate(seq):
        if x < 0:
            continue
        h = x % n
        j = h
        while j != pos:
            y = seq[j]
            if y >= 0 and y != x:
                adj.setdefault(y, set()).add(x)  # y -> x
                indeg[x] = indeg.get(x, 0) + 1
            j = (j + 1) % n
        indeg.setdefault(x, 0)  # ensure present even if 0

    # topo sort, smallest first
    heap = [k for k in keys if indeg.get(k, 0) == 0]
    heapq.heapify(heap)
    result = []

    while heap:
        k = heapq.heappop(heap)
        result.append(k)
        for nxt in adj.get(k, []):
            indeg[nxt] -= 1
            if indeg[nxt] == 0:
                heapq.heappush(heap, nxt)
    return result


n = int(input())
table = list(map(int, input().split()))
print(" ".join(map(str, reconstruct(table, n))))

"""
{
1: {32, 34, 12, 22},
13: {32, 34, 12, 22},
12: {32, 34, 22},
38: {32, 27, 22},
33: {32, 22},
34: {32, 22},
27: {32, 22},
21: {32},
22: {32}}
{33: 0, 1: 0, 13: 0, 12: 2, 34: 3, 38: 0, 27: 1, 22: 7, 32: 9, 21: 0}
"""
