arr = list(map(int, input().split()))
n = int(input())
ans = []
for v in arr:
    std = [1,2,3,4,5,6]
    idx = std.index(v)
    std[0], std[idx] = std[idx], std[0]
    std[1:] = sorted(std[1:])
    ans.append(std[-n])
print(' '.join(map(str, ans)))