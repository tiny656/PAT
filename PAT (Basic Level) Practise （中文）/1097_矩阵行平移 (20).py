n, k, x = map(int, input().split())
s = [0]*n
r_k = 1 # sequence iterator
for r in range(1, n+1):
    e = list(map(int, input().split()))
    if r % 2 == 1:
        # offset supplement
        for i in range(r_k):
            s[i] += x
        # original element
        for i in range(r_k, n):
            s[i] += e[i-r_k]
        # update iterator
        r_k += 1
        r_k = 1 if r_k == k+1 else r_k
    else:
        for i in range(0, n):
            s[i] += e[i]

print(' '.join(map(str, s)))