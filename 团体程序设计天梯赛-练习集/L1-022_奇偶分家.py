n = input()
nums = map(int, input().split())
cnt = [0, 0]
for i in nums:
	cnt[i%2] += 1

print("%d %d" % (cnt[1], cnt[0]))
