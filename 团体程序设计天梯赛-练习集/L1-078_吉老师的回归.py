n, m = map(int, input().split())
ans = 'Wo AK le'
for i in range(n):
    q = input()
    if 'qiandao' not in q and 'easy' not in q:
        m -= 1
        if m == -1: ans = q
print(ans)