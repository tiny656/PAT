pa, pb = map(int, input().split())
judge = list(map(int, input().split()))
ja = 3 - sum(judge)
jb = sum(judge)
if (pa > pb and ja > 0) or (pa < pb and ja == 3):
    print("The winner is a: %d + %d" % (pa, ja))
else:
    print("The winner is b: %d + %d" % (pb, jb))