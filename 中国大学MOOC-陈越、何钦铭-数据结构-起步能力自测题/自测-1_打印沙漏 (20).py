#coding: utf-8
import math

n, ch = raw_input().split()
n = int(n)

lvl = int(math.sqrt((n+1)/2))
total = 2*lvl**2-1 # fomula: Sn = 2*n^2 -1

def BuildSandGlass(lvl, totLvl, ch):
    if (lvl == 1):
        return ' ' * (totLvl-1) + ch
    else:
        s = ' ' * (totLvl-lvl) + ch*(2*lvl-1)
        return '%s\n%s\n%s' % (s, BuildSandGlass(lvl-1, totLvl, ch), s)

print BuildSandGlass(lvl, lvl, ch)
print n - total