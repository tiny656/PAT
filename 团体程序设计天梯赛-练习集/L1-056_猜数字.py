n = int(input())
s = 0
d = []
for i in range(n):
    name, val = input().split()
    val = int(val)
    d += [(name, val)]
    s += val
avg = s // n // 2

winner = d[0][0]
t = d[0][1]

for i in range(n):
    if abs(d[i][1] - avg) < t:
        t = abs(d[i][1] - avg)
        winner = d[i][0]
        
print("%d %s" % (avg, winner))