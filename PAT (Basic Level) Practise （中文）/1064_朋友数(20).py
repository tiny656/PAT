#coding: utf-8

raw_input()
s = set([])
s = set(map(lambda x: sum(map(int, list(x))), raw_input().split()))
print len(s)
print ' '.join(map(str, sorted(list(s))))
