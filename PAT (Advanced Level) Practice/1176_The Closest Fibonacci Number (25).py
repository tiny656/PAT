fib = [0, 1]

count = 0
while fib[-1] <= 10**8:
    new = fib[-1] + fib[-2]
    fib.append(new)

v = int(input())
ans, diff = -1, 10**8
for i in range(len(fib)):
    if fib[i] >= v:
        if abs(fib[i] - v) < diff:
            ans = fib[i]
        break
    else:
        ans = fib[i]
        diff = abs(fib[i] - v)
print(ans)
