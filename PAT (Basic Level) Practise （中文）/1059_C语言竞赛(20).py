#coding: utf-8

'''
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
'''


prim = [True]*10001
prim[0] = prim[1] = False
for i in xrange(2, 10001):
    if prim[i]:
        for j in xrange(2, 10001):
            if i*j > 10000: break
            prim[i*j] = False
N = int(raw_input())
data = { raw_input() : i+1 for i in xrange(N) }
K = int(raw_input())
for i in xrange(K):
    id = raw_input()

    if data.has_key(id) and data[id] == 'Checked':
        print '%s: Checked' % id
        continue

    if not data.has_key(id):
        print '%s: Are you kidding?' % id
    else:
        if data[id] == 1:
            print '%s: Mystery Award' % id
        elif prim[data[id]]:
            print '%s: Minion' % id
        else:
            print '%s: Chocolate' % id
        data[id] = 'Checked'