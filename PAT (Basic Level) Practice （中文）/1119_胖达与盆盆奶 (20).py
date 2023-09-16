# construct peak array from left and right, then find the max of each element in the two arrays
# stands for the max height, then add 1 and multiply 100 is required the volume of milk
n = int(input())
arr = list(map(int, input().split()))

left, right = [1], [1]
for i in range(1, n):
	if arr[i] > arr[i-1]:
		left.append(left[i-1] + 1)
	elif arr[i] == arr[i-1]:
		left.append(left[i-1])
	else:
		left.append(1)

for i in range(n-2, -1, -1):
	if arr[i] > arr[i+1]:
		right.append(right[n-i-2] + 1)
	elif arr[i] == arr[i+1]:
		right.append(right[n-i-2])
	else:
		right.append(1)

right = list(reversed(right))

ans = 0
for i in range(n):
	ans += (max(left[i], right[i]) + 1) * 100
print(ans)