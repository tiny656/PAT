def printPair(p, vis):
    g = 0
    a, b = "", ""
    for i in range(len(p)):
        if not vis[i]:
            vis[i] = True
            g = int(p[i][0])
            a = p[i][1]
            break   

    for i in range(len(p)-1, -1, -1):
        if not vis[i] and int(p[i][0]) == (g + 1) % 2:
            vis[i] = True
            b = p[i][1]
            break
    print("%s %s" % (a, b))
    
    
n = int(input())
p = []
vis = [False] * n
for i in range(n):
    p.append(input().split())

for i in range(n // 2):
    printPair(p, vis)


