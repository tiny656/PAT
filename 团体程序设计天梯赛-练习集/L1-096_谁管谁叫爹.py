def get_digit_sum(n):
	sum = 0
	while n > 0:
		sum += n % 10
		n //= 10
	return sum

n = int(input())
for i in range(n):
	a, b = map(int, input().split())
	sa, sb = get_digit_sum(a), get_digit_sum(b)
	if a % sb == 0 and b % sa != 0:
		print("A")
	elif b % sa == 0 and a % sb != 0:
		print("B")
	else:
		print("A" if a > b else "B")