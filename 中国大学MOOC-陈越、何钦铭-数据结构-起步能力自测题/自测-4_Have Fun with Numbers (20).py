#coding: utf-8

n = int(raw_input())
n2 = 2*n

isFunNumber = ''.join(sorted(list(str(n)))) ==  ''.join(sorted(list(str(n2))))
print 'Yes' if isFunNumber else 'No'
print n2

