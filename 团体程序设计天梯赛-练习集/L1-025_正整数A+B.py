def intTryParse(value):
    for i in range(1, 1001):
        if value == str(i):
            return value, True
    return "?", False

a, b = input().split(" ", 1)

ans = []

va, erra = intTryParse(a)
vb, errb = intTryParse(b)
ans.append(va)
ans.append(vb)
if not erra or not errb:
    ans.append("?")
else:
    ans.append(str(int(va) + int(vb)))
    
print("%s + %s = %s" % (ans[0], ans[1], ans[2]))