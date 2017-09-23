#coding: utf-8
n = int(raw_input())
for i in xrange(n):
    z = raw_input()
    a, b = int(z[:len(z)/2]), int(z[len(z)/2:])
    z = int(z)
    check = (a*b != 0) and z % (a*b) == 0
    print '%s' % 'Yes' if check else 'No'
