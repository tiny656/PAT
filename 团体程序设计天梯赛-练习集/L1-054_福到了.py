ch, rows = input().split()
rows = int(rows)
mat = [[0] for i in range(rows)]
mat_new = [[0] for i in range(rows)]
 
for i in range(rows):
    mat[i] = "%*s" % (rows, input().replace('@', ch))
    mat_new[i] =mat[i][::-1]

mat_new = mat_new[::-1]

isSame = True
for i in range(rows):
    if mat[i] != mat_new[rows - i - 1]:
        isSame = False
        break

if isSame:
    print("bu yong dao le")

for r in mat_new:
    print(r)