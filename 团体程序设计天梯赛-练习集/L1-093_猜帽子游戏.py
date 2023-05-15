n = int(input())
ans = list(map(int, input().split()))
k = int(input())
for i in range(k):
	guess = list(map(int, input().split()))
	isOk = True
	for j in range(n):
		if guess[j] != 0 and guess[j] != ans[j]:
			isOk = False
			break
	isOk &= sum(guess) != 0
	print("Da Jiang!!!" if isOk else "Ai Ya")