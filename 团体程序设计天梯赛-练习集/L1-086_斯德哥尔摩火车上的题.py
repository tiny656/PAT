def gets(a):
    s = 0
    for i in range(1, len(a)):
        if a[i] % 2 == a[i-1] % 2:
            s = s * 10 + max(a[i], a[i-1])
    return s

a1, a2 = list(map(int, list(input()))), list(map(int, list(input())))
r1, r2 = gets(a1), gets(a2)
if r1 == r2:
    print(r1)
else:
    print(r1)
    print(r2)