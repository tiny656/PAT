def isPrime(n):
    if n <= 1: return False
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

ans = None
n = int(input())
if isPrime(n):
    if n-6 > 0 and isPrime(n-6):
        ans = "Yes\n%d" % (n-6)
    elif n+6 > 0 and isPrime(n+6):
        ans = "Yes\n%d" % (n+6)

if not ans:
    ans = "No\n"
    seed = n+1
    while True:
        if isPrime(seed) and (seed-6 > 0 and isPrime(seed-6) or isPrime(seed+6)):
            ans += str(seed)
            break
        seed += 1
print(ans)
