#coding:utf-8

n = int(raw_input())
w = [0, 0]
for i in range(n):
    a0, a1, b0, b1 = map(int, raw_input().split())
    if a1 != b1:
        w[0] += 1 if a1 == a0+b0 else 0
        w[1] += 1 if b1 == a0+b0 else 0
print w[1], w[0]