a, b = map(int, raw_input().split())
arr = xrange(a ,b+1, 1)
tot = sum(arr)

out = ''
for index, value in enumerate(arr):
    if index != 0 and index % 5 == 0:
        out += '\n'
    out += '{:5}'.format(value)
out += '\nSum = %d' % tot
print out


