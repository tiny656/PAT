#coding: utf-8

n = int(raw_input())
ans = ''
for i in xrange(n):
    for sel in  raw_input().split():
        if sel[-1] == 'T':
            ans += str(ord(sel[0]) - ord('A') + 1)
print ans
