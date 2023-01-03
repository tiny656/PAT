#coding: utf-8
n = int(raw_input())
ans = -1
for i in xrange(n):
    a, b = map(float, raw_input().split())
    ans = max((a**2+b**2)**0.5, ans)
print '%.2f' % round(ans, 2)