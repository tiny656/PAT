h, m = map(int, raw_input().split(':'))
s = 'PM' if h >= 12 else 'AM'
h = h - 12 if h > 12 else h
print '%d:%d %s' % (h, m, s)