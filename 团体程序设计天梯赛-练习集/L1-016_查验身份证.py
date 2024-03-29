def IsValid(s):
    w = [7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2]
    M = [1, 0, 'X', 9, 8, 7, 6, 5, 4, 3, 2]
    ok = True
    s = list(s)
    for i in range(17):
        ok &= s[i].isdigit()
    if not ok: return ok
    m = 0
    for i in range(17):
        m += int(s[i]) * w[i]
    ok &= (str(M[m%11]) == s[17])
    return ok

n = int(input())
notPassed = []
for i in range(n):
    s = input()
    if not IsValid(s):
        notPassed.append(s)

if 0 == len(notPassed):
    print("All passed")
else:
    for s in notPassed:
        print(s)
