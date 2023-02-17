def isPrime(n):
	if n == 1:
		return False
	for i in range(2, int(n**0.5)+1):
		if n % i == 0:
			return False
	return True

d = input()

ok = True
for i in range(len(d)):
	t = d[i:]
	r = isPrime(int(t))
	ok &= r
	print("{} {}".format(t, "Yes" if r else "No"))
if ok:
	print("All Prime!")