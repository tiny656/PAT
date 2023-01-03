#coding: utf-8
def gcd(a,b):
    if b==0: return a
    else: return gcd(b, a%b)

a,b,c = raw_input().split()
n1, m1 = map(int, a.split('/'))
n2, m2 = map(int, b.split('/'))
# 考虑顺序
if n1 * m2 > n2 * m1:
    n1,n2,m1,m2 = n2,n1,m2,m1

c = int(c)
ans = []
x = n1*c/m1+1
while n1*c<x*m1 and n2*c>x*m2:
    if gcd(x, c) == 1:
        ans.append('%d/%d' % (x, c))
    x += 1
print ' '.join(ans)
