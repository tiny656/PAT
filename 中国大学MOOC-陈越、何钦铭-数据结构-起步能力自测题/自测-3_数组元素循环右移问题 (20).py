#coding: utf-8

# (A'B')' = BA, '表示转置

n, m = map(int, raw_input().split())
arr = raw_input().split()

pos = m % n
# print ' '.join(reversed(list(reversed(arr[:-pos])) + list(reversed(arr[-pos:]))))
print ' '.join((arr[n-pos-1::-1] + arr[:n-pos-1:-1])[::-1])