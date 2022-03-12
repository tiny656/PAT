def is_square(x):
    lo, hi = 1, x
    while lo <= hi:
        mid = (lo + hi) // 2
        if mid * mid == x: return True
        elif mid * mid > x: hi = mid - 1
        else: lo = mid + 1
    return False


m, n = map(int, input().split()) 

ans = []
for a in range(m, n+1):
    c_2 = a*a*a - (a-1)*(a-1)*(a-1)
    if not is_square(c_2): continue
    c = int(c_2**0.5)

    t = 2*c-1
    if not is_square(t): continue
    t_0_5 = int(t**0.5)
    if t_0_5 % 2 == 0: continue
    b = (1+t_0_5) // 2
    if b <= 0 or b == 1: continue # (1, 1) is not a valid result ????
    ans.append("%d %d" % (a, b))
if not ans:
    print("No Solution")
else:
    print('\n'.join(ans))
