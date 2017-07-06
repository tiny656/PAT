#coding: utf-8

n = int(raw_input())
couple = {}
for i in xrange(n):
    a, b = raw_input().split()
    couple[a], couple[b] = b, a
m = int(raw_input())
ans = []
vip = set(raw_input().split())
for sir in vip:
    if couple.has_key(sir) and couple[sir] in vip:
        continue
    ans.append(sir)
print len(ans)
if ans: print ' '.join(sorted(ans))

