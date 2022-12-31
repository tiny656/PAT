feeling = list(map(int, input().split()))
while True:
    q = int(input())
    if q < 0 or q > 23 : break

    v = feeling[q]
    r = 'Yes' if v > 50 else 'No'
    print('%d %s' % (v, r))