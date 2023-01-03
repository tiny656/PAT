#coding: utf-8
# 排序，从小到大组合
# res = a0/2^(n-1) + a1/2^(n-2) + ... + an/2 , so a0...an升序，res值最大
n = int(raw_input())
elem = map(int, raw_input().split())
elem.sort()
tot = elem[0]
for i in xrange(1, len(elem)):
	tot = (tot + elem[i]) / 2.
print int(tot)
