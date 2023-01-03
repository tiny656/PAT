#coding: utf-8

n = int(raw_input())
v = map(float, raw_input().split(' '))
ans = 0.0
for i in range(1, n+1):
    ans += float(i*(n-i+1)) * v[i-1]
print "%.2f" % ans