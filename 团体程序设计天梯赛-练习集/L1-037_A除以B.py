a, b = map(int, input().split())
ans = [str(a), str(b)]
if b == 0:
    ans.append("Error")
else:
    ans.append("%.2f" % (a/b))
    if b < 0:
        ans[1] = "(%s)" % ans[1]

print("%s/%s=%s" % (ans[0], ans[1], ans[2]))
    
