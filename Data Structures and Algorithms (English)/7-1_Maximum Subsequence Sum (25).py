n = int(input())
arr = list(map(int, input().split()))

max_val = max(arr)
if max_val < 0:
    print(0, arr[0], arr[-1])
elif max_val == 0:
    idx = arr.index(0)
    print(0, arr[idx], arr[idx])
else:
    curr, ans, start, l, r = 0, 0, 0, 0, 0
    for i, x in enumerate(arr):
        curr += x
        if curr > ans:
            ans, l, r = curr, start, i
        if curr < 0:
            curr = 0
            start = i + 1
    print(ans, arr[l], arr[r])
