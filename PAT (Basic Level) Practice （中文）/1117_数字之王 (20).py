def func(arr):
	is_all_single = True
	mem = []
	for i, v in enumerate(arr):
		if v >= 10: is_all_single = False

		r = 0 if v == 0 else 1
		while v != 0:
			r *= (v % 10) ** 3
			v //= 10

		v, r = r, 0
		while v != 0:
			r += v % 10
			v //= 10

		mem.append((i, r))
	if is_all_single: return
	else:
		for i, v in mem:
			arr[i] = v
		func(arr)

n1, n2 = map(int, input().split())
arr = [i for i in range(n1, n2+1)]

func(arr)
max_count = 0
ans = []
for v in set(arr):
	cnt = arr.count(v)
	max_count = max(max_count, cnt)
	ans.append((v, cnt))

ans = filter(lambda x: x[1] == max_count, ans)
ans = sorted(ans, key=lambda x: x[0])
print(max_count)
print(' '.join(map(lambda x: str(x[0]), ans)))