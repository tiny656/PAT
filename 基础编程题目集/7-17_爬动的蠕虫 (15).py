n, u, d = map(int, raw_input().split())
m = 0
dis = 0
while True:
    m += 1

    if m % 2 == 1:
        dis += u
    else:
        dis -= d

    if dis >= n: 
        break

print m
