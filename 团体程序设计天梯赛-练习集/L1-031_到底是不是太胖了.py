n = int(input())
for i in range(n):
    h, w = map(int, input().split())
    s = (h - 100) *0.9 * 2
    l = abs(s - w)
    r = s * 0.1
    if l < r:
        print("You are wan mei!")
    else:
        if w > s:
            print("You are tai pang le!")
        else: 
            print("You are tai shou le!")
