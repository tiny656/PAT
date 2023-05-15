def get_divisor(n):
	divisor = []
	for i in range(2, n+1):
		if n % i == 0:
			divisor.append(i)
	return divisor


n0, n1, n = map(int, input().split())
divisor0 = set(get_divisor(n0))
divisor1 = set(get_divisor(n1))
diff = 10**5+1
ans = (-1, -1)
for f in divisor0:
	m = n1 // (n-n0//f)
	if n1 % (n-n0//f) == 0 and m in divisor1 and abs(f-m) < diff:
		diff = abs(f-m)
		ans = (n0//f, n-n0//f)

if ans == (-1, -1):
	print("No Solution")
else:
	print(ans[0], ans[1])