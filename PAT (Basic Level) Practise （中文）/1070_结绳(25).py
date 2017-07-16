#coding: utf-8
n = int(raw_input())
elem = map(int, raw_input().split())
elem.sort()
tot = elem[0]
for i in xrange(1, len(elem)):
	tot = (tot + elem[i]) / 2.

print int(tot)
