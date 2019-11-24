def isNumber(e):
    if len(e) >= 1 and e[0].isdigit(): return True
    elif len(e) > 1 and (e[0] == '-' or '+'): return True
    else: return False

s = raw_input().split()
r = []

for e in s:
    r.append(e)
    while len(r) >= 3 and not isNumber(r[-3]) and isNumber(r[-2]) and isNumber(r[-1]):
        try:
            ex = 'float(%s)%sfloat(%s)' % (r[-2], r[-3], r[-1]) # avoid int dividen
            result = eval(ex)
        except:
            print 'ERROR'
            exit(0)
        r = r[:-3]
        r.append(str(result))

if len(r) == 1 and isNumber(r[0]):
    print '%.1f' % float(r[0])
else:
    print 'ERROR'