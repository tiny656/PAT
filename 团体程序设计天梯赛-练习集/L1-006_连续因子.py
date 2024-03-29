n = int(input())
maxn = int(n ** 0.5) + 1

begin = 1
maxCount = 0
for i in range(2, maxn+1, 1):
    p = 1
    count = 0
    for j in range(i, maxn+1, 1):
        p *= j
        count += 1
        if n % p == 0:
            if count > maxCount:
                maxCount = count
                begin = i
        else:
            break
            
if begin == 1:
    print("1\n{}".format(n))
else:
    print(maxCount)
    print( "*".join(map(str, range(begin, begin+maxCount, 1))))
