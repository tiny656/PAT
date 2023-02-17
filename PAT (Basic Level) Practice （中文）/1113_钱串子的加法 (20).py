bs="0123456789abcdefghijklmnopqrstuvwxyz"

def add(a, b, base):
	a, b = a[::-1], b[::-1]
	c = ""
	carry = 0
	for i in range(max(len(a), len(b))):
		if i < len(a):
			carry += bs.index(a[i])
		if i < len(b):
			carry += bs.index(b[i])
		c += bs[carry % base]
		carry //= base
	if carry:
		c += bs[carry]
	while len(c) > 1 and c[-1] == "0":
		c = c[:-1]
	return c[::-1]

a, b = input().split()
print(add(a, b, 30))