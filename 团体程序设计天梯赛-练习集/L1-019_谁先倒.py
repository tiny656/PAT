pa, pb = map(int, input().split())
n = int(input())
acup, bcup = 0, 0
for i in range(n):
    if acup > pa or bcup > pb:
        continue

    a1, a2, b1, b2 = map(int, input().split())
    alose = a2 == a1+b1
    blose = b2 == a1+b1
    if alose and not blose:
        acup += 1
    elif blose and not alose:
        bcup += 1


if acup > pa:
    print("A")
    print(bcup)
elif bcup > pb:
    print("B")
    print(acup)