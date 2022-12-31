n, k, s = map(int, input().split())
score = {}
ans = 0
for i in range(n):
    s1, s2 = map(int, input().split())
    if s1 < 175: continue
    if s2 >= s: ans += 1
    else: score[s1] = score.get(s1, 0) + 1

for i in range(175, 291):
    if score.get(i, 0) >= k: ans += k
    else: ans += score.get(i, 0)
print(ans)
