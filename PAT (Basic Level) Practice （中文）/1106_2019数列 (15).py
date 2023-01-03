f = [2, 0, 1, 9]
ans = ""
n = int(input())
for i in range(n):
    if i >= 4:
        f[i%4] = sum(f) % 10
    ans += str(f[i%4])
print(ans)