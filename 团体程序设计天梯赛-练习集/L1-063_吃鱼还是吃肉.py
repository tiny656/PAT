n = int(input())
for i in range(n):
    g, h, w = map(int, input().split())
    if g == 1:
        hs, ws = 130, 27
    else:
        hs, ws = 129, 25
    
    ans = None
    if h < hs:
        ans = 'duo chi yu!'
    elif h == hs:
        ans = 'wan mei!'
    else:
        ans = 'ni li hai!'
    
    if w < ws:
        ans += ' duo chi rou!'
    elif w == ws:
        ans += ' wan mei!'
    else:
        ans += ' shao chi rou!'
    print(ans)