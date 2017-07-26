#coding: utf-8
# 基础并查集 Union Set
class UnionSet(object):
    def __init__(self, num):
        self.num = num
        self.fa = [i for i in xrange(num+1)]
        self.rank = [0] * (num+1)


    def find(self, x):
        if self.fa[x] == x:
            return x
        else:
            self.fa[x] = self.find(self.fa[x])
            return self.fa[x]

    def connected(self, p, q):
        return self.find(p) == self.find(q)

    def union(self, p, q):
        fp, fq = self.find(p), self.find(q)
        if fp == fq:
            return
        if self.rank[fp] > self.rank[fq]:
            self.fa[fq] = fp
        else:
            self.fa[fp] = fq;
            if self.rank[fp] == self.rank[fq]:
                self.rank[fq] += 1
        self.num -= 1

n = int(raw_input())
inp_data = [0]*n
birds = 0
for pic in xrange(n):
    inp_data[pic] = map(int, raw_input().split()[1:])
    birds = max(birds, max(inp_data[pic]) if inp_data[pic] else 0)

us = UnionSet(birds)
for data in inp_data:
    for i in xrange(len(data)-1):
        us.union(data[i], data[i+1])

print us.num, birds

Q = int(raw_input())
for i in xrange(Q):
    p, q = map(int, raw_input().split())
    print 'Yes' if us.connected(p, q)  else 'No'
