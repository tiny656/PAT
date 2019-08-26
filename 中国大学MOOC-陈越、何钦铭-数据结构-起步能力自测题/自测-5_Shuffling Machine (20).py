#coding: utf-8

cards = [None]
cards = cards + ['S' + str(i) for i in xrange(1, 14, 1)]
cards = cards + ['H' + str(i) for i in xrange(1, 14, 1)]
cards = cards + ['C' + str(i) for i in xrange(1, 14, 1)]
cards = cards + ['D' + str(i) for i in xrange(1, 14, 1)]
cards = cards + ['J1', 'J2']
result = [None]*len(cards)

k = int(raw_input())
order = map(int, raw_input().split())
order.insert(0, None)
for i in xrange(1, len(order)):
    p = i
    for j in xrange(k):
        p = order[p]
    result[p] = cards[i]
print ' '.join(result[1:])

    
    