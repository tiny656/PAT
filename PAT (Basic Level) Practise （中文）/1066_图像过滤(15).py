#coding: utf-8

n, m, a, b, v = map(int, raw_input().split())
for i in xrange(n):
    result = map(lambda x: ('%03d' % v)if a<=int(x)<=b else ('%03d' % int(x)), raw_input().split())
    print ' '.join(result)