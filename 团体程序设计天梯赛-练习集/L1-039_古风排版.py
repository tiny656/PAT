import math
rows = int(input())
s = input()
cols = math.ceil(len(s)/rows)
m = [[0 for i in range(cols)] for j in range(rows)]
index = 0
for c in range(cols-1, -1, -1):
    for r in range(rows):
        if index < len(s):
            m[r][c] = s[index]
            index += 1
        else:
            m[r][c] = ' '

for r in m:
    print (''.join(r))
