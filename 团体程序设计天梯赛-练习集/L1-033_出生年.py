y, n = map(int, input().split())
r = None
for i in range(y, 10000, 1):
    d = {}
    for x in ("%04d" % i):
        d[x] = True
    if len(d) == n:
        r = i
        break
print("%d %04d" % (r - y, r))
