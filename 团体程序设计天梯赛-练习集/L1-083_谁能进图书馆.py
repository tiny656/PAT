a, b, c, d = map(int, input().split())

if c < a and d < a:
    print('%s-N %s-N' % (c, d))
    print('zhang da zai lai ba')
elif c >= a and d >= a:
    print('%s-Y %s-Y' % (c, d))
    print('huan ying ru guan')
elif c < a and d >= b:
    print('%s-Y %s-Y' % (c, d))
    print('qing 2 zhao gu hao 1')
elif d < a and c >= b:
    print('%s-Y %s-Y' % (c, d))
    print('qing 1 zhao gu hao 2')
elif c >= a:
    print('%s-Y %s-N' % (c, d))
    print('1: huan ying ru guan')
elif d >= a:
    print('%s-N %s-Y' % (c, d))
    print('2: huan ying ru guan')