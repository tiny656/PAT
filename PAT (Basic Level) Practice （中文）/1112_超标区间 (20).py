n, t = map(int, input().split())
points = list(map(int, input().split()))

m = max(points)
if m <= t:
	print(m)
else:
	begin = -1
	for i in range(n):
		if points[i] > t:
			if begin == -1:
				begin = i
		if points[i] <= t and begin != -1:
			print("[{}, {}]".format(begin, i-1))
			begin = -1
	if begin != -1:
		print("[{}, {}]".format(begin, n-1))
