n = int(input())
friends = {}
for i in range(n):
	k, *ids = input().split()
	for j in ids:
		friends[j] = friends.get(j, 0)
		friends[j] += len(ids) - 1
	
m = int(input())
ids = input().split()
ans = []
vis = {}
for i in ids:
	if i not in vis.keys() and (i not in friends.keys() or friends[i] <= 0):
		ans.append(i)
		vis[i] = True

if not ans:
	print("No one is handsome")
else:
	print(' '.join(ans))

