s = input()
cnt = {'G': 0, 'P': 0, 'L': 0, 'T': 0}
for ch in s:
	if ch.upper() in cnt.keys():
		cnt[ch.upper()] += 1

ans = []
keys = list(cnt.keys())
i = 0
while True:
	if sum(cnt.values())== 0:
		break

	if cnt[keys[i]] != 0:
		ans.append(keys[i])
		cnt[keys[i]] -= 1

	i += 1
	i %= 4

print(''.join(ans))