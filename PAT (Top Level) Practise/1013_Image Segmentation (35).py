#coding: utf-8

# 基于最小生成树的图像分割算法，对于图片来说就是像素点的4连通或8连通构图
class Component(object):
    def __init__(self, c):
        self.size = 1
        self.minWeight = 0x7fffffff

class UnionSet(object):
    def __init__(self, n):
        self.size = n
        self.rank = [0]*n
        self.fa = [None]*n
        self.components = [None]*n

    def makeSet(self, c):
        for i in xrange(self.size):
            self.fa[i] = i
            self.rank[i] = 0
            self.components[i] = Component(c)

    def find(self, x):
        return x if self.fa[x] == x else self.find(self.fa[x])

    def findComponent(self, x):
        return self.components[self.find(x)]

    def union(self, x, y, edgeWeight):
        if self.isConnect(x, y): return
        fx, fy = self.find(x), self.find(y)
        if self.rank[fx] < self.rank[fy]:
            self.fa[fx] = fy
            self.components[fy].size += self.components[fx].size
            self.components[fy].minWeight = min(edgeWeight, self.components[fx].minWeight)
        else:
            self.fa[fy] = fx
            if self.rank[fx] == self.rank[fy]: self.rank[fx] += 1
            self.components[fx].size += self.components[fy].size
            self.components[fx].minWeight = min(edgeWeight, self.components[fy].minWeight)

    def isConnect(self, x, y):
        return self.find(x) == self.find(y)

nv, ne, c = map(int, raw_input().split())
edges = [None]*ne

us = UnionSet(nv)
us.makeSet(c)

for i in xrange(ne):
    a, b, w = map(int, raw_input().split())
    edges[i] = (a, b, w)
edges.sort(key=lambda x: x[2])

for a, b, w in edges:
    c1, c2 = us.findComponent(a), us.findComponent(b)
    h1 = c1.minWeight + c/float(c1.size)
    h2 = c2.minWeight + c/float(c2.size)
    if w <= h1 and w <= h2: us.union(a, b, w)

d = {}
for i in xrange(nv):
    d.setdefault(us.find(i), []).append(i)
print '\n'.join(' '.join(map(str, component)) for component in sorted(d.values()))