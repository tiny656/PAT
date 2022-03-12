n = int(input())
tot = [0, 0]
ans = [None, None]
for i in range(n):
    id, price, count = input().split()
    price, count = int(price), int(count)
    if count >= tot[0]:
        tot[0] = count
        ans[0] = id
    
    if count * price >= tot[1]:
        tot[1] = count * price
        ans[1] = id

print("%s %d" % (ans[0], tot[0]))
print("%s %d" % (ans[1], tot[1]))


