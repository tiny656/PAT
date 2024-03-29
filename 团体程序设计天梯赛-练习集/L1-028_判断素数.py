def isPrime(v):
    if v == 1: return False
    
    i = 2
    while i*i <= v:
        if v % i == 0:
            return False
        i += 1
    return True

n = int(input())
for i in range(n):
    k = int(input())
    if isPrime(k):
        print("Yes")
    else:
        print("No")
