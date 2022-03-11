def check(n, factors):
    # check all combinations if valid
    for n1 in range(0, len(factors)):
        for n2 in range(n1+1, len(factors)):
            for n3 in range(n2+1, len(factors)):
                for n4 in range(n3+1, len(factors)):
                    s = factors[n1] + factors[n2] + factors[n3] + factors[n4]
                    if s % n == 0:
                        return True
    return False

k = int(input())
nums = map(int, input().split())
for t in nums:
    # find all factors
    factors = []
    for i in range(1, t//2+1):
        if t % i == 0:
            factors.append(i)
    factors.append(t)

    print("Yes" if check(t, factors) else "No")
