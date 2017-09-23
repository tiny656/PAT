#coding: utf-8
# 枚举所有边，判断是否能被点集覆盖
n, m = map(int, raw_input().split())
edges = [None] * m
for i in xrange(m):
    a, b = map(int, raw_input().split())
    edges[i] = (a, b)

k = int(raw_input())
for i in xrange(k):
    v_set = set(map(int, raw_input().split()[1:]))
    for e_a, e_b in edges:
        if e_a not in v_set and e_b not in v_set:
            print 'No'
            break
    else:
        print 'Yes'
