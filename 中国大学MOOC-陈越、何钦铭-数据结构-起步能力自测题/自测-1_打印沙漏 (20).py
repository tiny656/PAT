#coding: utf-8
import math

n, ch = raw_input().split()
n = int(n)

lvl = int(math.sqrt((n+1)/2))
total = 2*lvl**2-1 # fomula: Sn = 2*n^2 -1

def BuildSandGlass(lvl, whitespace, ch):
    if (lvl == 1):
        return ' ' * whitespace + ch
    else:
        s = ' ' * whitespace + ch*(2*lvl-1)
        return '%s\n%s\n%s' % (s, BuildSandGlass(lvl-1, whitespace+1, ch), s)

print BuildSandGlass(lvl, 0, ch)
print n - total