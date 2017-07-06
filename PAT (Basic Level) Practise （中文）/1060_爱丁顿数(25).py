#coding: utf-8

# 2 3 6 6 7 7 8 8 9 10

N = int(raw_input())
dis = map(int, raw_input().split())
dis.sort(reverse=True)
dis.append(-1)
ans = 1
for i in xrange(N+1):
    if dis[i] <= i+1: # wtf 把超过看成小于等于。。。
        ans = i
        break
print ans