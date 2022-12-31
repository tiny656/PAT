ra, ca = map(int, input().split())
mat1 = [[0] for _ in range(ra)]
for i in range(ra):
    mat1[i] = [int(v) for v in input().split()]

rb, cb = map(int, input().split())
mat2 = [[0] for _ in range(rb)]
for i in range(rb):
    mat2[i] = [int(v) for v in input().split()]

if ca != rb:
    print("Error: %d != %d" % (ca, rb))
else:
    print("%d %d" % (ra, cb))
    mat3 = [[0] * cb for i in range(ra)]
    for i in range(ra):
        for j in range(cb):
            for k in range(ca):
                mat3[i][j] += mat1[i][k] * mat2[k][j]
    for i in range(ra):
        print(" ".join(map(str, mat3[i])))
