n = int(input())
for i in range(n):
    name, h, m = input().split()
    h, m = int(h), int(m)
    if not (15 <= h <= 20) or not (50 <= m <= 70):
        print(name)
