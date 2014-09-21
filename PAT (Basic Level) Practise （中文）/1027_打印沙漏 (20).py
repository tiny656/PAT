n, ch = map(str, raw_input().split(' '))
n = int(n)
num = int(((n+1)/2.0) ** 0.5)
left = n - 2 * (num ** 2) + 1
symbol = [2*i-1 for i in range(num, 0, -1)] + [2*i+1 for i in range(1, num, 1)]
whitespace = [i for i in range(0, num, 1)] + [i for i in range(num-2, -1, -1)]
for i in range(len(symbol)):
	line = ""
	for j in range(whitespace[i]):
		line += " "
	for j in range(symbol[i]):
		line += ch
	print line
print left