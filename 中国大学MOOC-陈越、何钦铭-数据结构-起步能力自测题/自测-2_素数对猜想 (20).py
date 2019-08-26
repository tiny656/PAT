#coding: utf-8

# 筛法求所有小于等于n的素数
n = int(raw_input())
isPrime = [True] * (n+1)
isPrime[0] = isPrime[1] = False
primes = []
for i in xrange(2, n+1, 1):
    if not isPrime[i]: continue
    primes.append(i)
    for j in xrange(i+i, n+1, i):
        isPrime[j] = False

count = 0
for i in xrange(1, len(primes)):
    if primes[i] - primes[i-1] == 2:
        count += 1
print count