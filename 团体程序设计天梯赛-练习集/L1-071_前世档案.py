n, m = map(int, input().split())
for i in range(m):
    lo, hi = 0, 2**n-1
    ans = input()
    for ch in ans:
        if ch == 'y':
            hi = (lo + hi) // 2
        else:
            lo = (lo + hi) // 2 + 1
    print(lo+1)