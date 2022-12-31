p1, p2, p3, p4, low, limit = map(int, input().split())
p = [p1, p2, p3, p4]
maxp = max(p)

c1 = list(map(lambda p: maxp-p <= limit and p >= low, p))

if all(val for val in c1):
    print('Normal')
elif c1.count(False) >= 2:
    print('Warning: please check all the tires!')
else:
    print('Warning: please check #%d!' % (1+c1.index(False)))