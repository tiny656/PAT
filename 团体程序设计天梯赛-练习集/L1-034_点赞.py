n = int(input())
r = [0, None]
d = {}
for i in range(n):
    k, *f = map(int, input().split())
    for j in f:
        d[j] = d.setdefault(j, 0) + 1
        if d[j] > r[0]:
            r[0] = d[j]
            r[1] = j
        elif d[j] == r[0]:
            if j > r[1]:
                r[1] = j
                
print("%d %d" % (r[1], r[0]))
