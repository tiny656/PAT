#coding: utf-8
n, m = map(int, raw_input().split())
for i in xrange(n):
    scores = map(int, raw_input().split())
    G1 = scores[0]
    otherGroup = filter(lambda x: 0 <= x <= m, scores[1:])
    G2 = (sum(otherGroup) - max(otherGroup) - min(otherGroup)) / (len(otherGroup) - 2.)
    print '%.0f' % round((G1+G2)/2.)
