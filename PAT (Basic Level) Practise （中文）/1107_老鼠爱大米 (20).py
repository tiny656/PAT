n, m = map(int, input().split())
ans = []
for i in range(n):
    g = map(int, input().split())
    ans.append(max(g))

print(" ".join(map(str, ans)))
print(max(ans))