input()
arr = map(int, input().split())
# filter out even numbers
arr = list(filter(lambda v: v % 2 == 1, arr))
result = arr[0]
# xor remove odd number pair
for i in range(1, len(arr)):
    result ^= arr[i]
print(result)
