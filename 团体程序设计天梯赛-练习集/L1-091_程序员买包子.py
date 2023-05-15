n, x, m, k = input().split()
n, m, k = int(n), int(m), int(k)

if k == n:
	print('mei you mai {} de'.format(x))
elif k == m:
	print('kan dao le mai {} de'.format(x))
else:
	print('wang le zhao mai {} de'.format(x))

