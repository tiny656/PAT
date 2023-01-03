#coding: utf-8
import sys

t, k = map(int, raw_input().split())
for i in xrange(k):
    n1, b, t_, n2 = map(int, raw_input().split())
    if t < t_:
        print 'Not enough tokens.  Total = %d.' % t
    else:
        isWin = (n1 > n2 and b == 0) or (n1 < n2 and b == 1)
        if isWin:
            t += t_
            print 'Win %d!  Total = %d.' % (t_, t)
        else:
            t -= t_
            print 'Lose %d.  Total = %d.' % (t_, t)
            if t == 0:
                print 'Game Over.'
                sys.exit(0)

