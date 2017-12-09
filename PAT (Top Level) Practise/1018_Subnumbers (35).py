#coding: utf-8
'''
统计每位的贡献值
定义f[i]是第i位的贡献值，比如abc,i为a这位，那么f[i] = a+ab+abc = a + a*10 + b + a*100 + b*10 + c
f[i]的递推关系：比如xabc
那么当前x为
f[i] = x + xa + xab + xabc = x*1 + x*10+a + x*100+a*10+b + x*1000+a*100+b*10+c = x + x*10 + x*100 + x*1000 + (a + a*10 + b + a*100 + b*10 + c) = x*(1+10+100+1000) + f[i+1]
= x*1111 + f[i+1]
'''
MOD = 1000000007
n = map(int, list(raw_input()))

f, b = [0] * (len(n)+1), 0
for i in xrange(len(n)-1, -1, -1):
    b = (b*10 + 1) % MOD
    f[i] = (n[i]*b) % MOD + f[i+1]
    f[i] %= MOD

ret = 0
for i in xrange(len(n)):
    ret += 0 if n[i] == 0 else f[i]
    ret %= MOD
print ret