a1, a2, n = map(int, input().split())
count = n
ans = [a1, a2]
i = 0
while n > 2:
    c = ans[i] * ans[i+1]
    if c >= 10:
        ans.append(c // 10)
        ans.append(c % 10)
        i += 1
        n -= 2
    else:
        ans.append(c)
        i += 1
        n -= 1

print(' '.join(map(str, ans[:count])))