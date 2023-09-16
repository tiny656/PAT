s = input()
if len(s) % 2 == 1:
	print('Error: %d digit(s)' % len(s))
else:
	a, b = int(s[:len(s)//2]), int(s[len(s)//2:])
	if b - a == 2:
		print('Yes: %d - %d = 2' % (b, a))
	else:
		print('No: %d - %d != 2' % (b, a))