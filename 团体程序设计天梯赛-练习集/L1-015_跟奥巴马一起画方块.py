n, m = input().split()
n = int(n)
col = n
row = int(n / 2. + 0.5)
for r in range(row):
    for c in range(col):
        print(m, end='')
    print()
