# search pruning for below conditions
# 1. search set size greater than k
# 2. sum of search set greater than m
# 3. sum of current search set plus remaining all '9' numbers still less than m

def search(s, k, m, results):
    sum_s = sum(s)
    if (len(s) > k or sum_s > m or sum_s + (k - len(s)) * 9 < m): return
    if len(s) == k and sum_s == m:
        results.append(int("".join(map(str, s))))
        return

    start = 1 if len(s) == 0 else 0
    for i in range(start, 10):
        s.append(i)
        search(s, k, m, results)
        s.pop(-1)

def gcd(a, b):
    if b == 0: return a
    else: return b if a % b == 0 else gcd(b, a%b)

def is_prime(n):
    lo = 2
    hi = int(n**0.5)+1
    for i in range(lo, hi):
        if n % i == 0: return False
    return True

n = int(input())
for i in range(n):
    k, m = map(int, input().split())
    results = []
    search([], k, m, results)
    print("Case %d" % (i+1))
    ans = []
    is_ok = False
    for r in results:
        m1 = sum(map(int, list(str(r+1))))
        g = gcd(m, m1)
        if g > 2 and is_prime(g):
            is_ok = True
            ans.append((m1, r))
        
    if not is_ok:
        print("No Solution")
    else:
        ans.sort(key=lambda x:(x[0], x[1]))
        print("\n".join(map(lambda x: "%d %d" % (x[0], x[1]), ans)))