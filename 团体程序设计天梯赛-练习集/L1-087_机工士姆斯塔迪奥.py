n, m, q = map(int, input().split())
tot = n * m
nRow, nCol = set([]), set([])
for i in range(q):
    t, c = map(int, input().split())
    if t == 0:
        nRow.add(c)
    else:
        nCol.add(c)
print(tot - len(nRow) * m - len(nCol) * n + len(nRow) * len(nCol))