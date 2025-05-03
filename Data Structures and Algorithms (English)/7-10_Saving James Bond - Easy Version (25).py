import math


def dist(a, b):
    return math.hypot(a[0] - b[0], a[1] - b[1])


def can_escape(croc, D):
    """判断鳄鱼 croc=(x,y) 能否一步跳到岸"""
    x, y = croc
    return 50 - max(abs(x), abs(y)) <= D


n, d = list(map(int, input().split()))
crocs = []
for _ in range(n):
    x, y = list(map(int, input().split()))
    crocs.append((x, y))

# 直接从岛跳到岸
if d >= 42.5:  # 50 - 7.5
    print("Yes")

# 找第一跳可达的鳄鱼
first = [i for i, (x, y) in enumerate(crocs) if dist((0, 0), (x, y)) <= d + 7.5]

visited = [False] * n
queue = first[:]

is_escaped = False
while queue and not is_escaped:
    i = queue.pop()
    if visited[i]:
        continue
    visited[i] = True

    if can_escape(crocs[i], d):
        is_escaped = True

    if not is_escaped:
        for j in range(n):
            if not visited[j] and dist(crocs[i], crocs[j]) <= d:
                queue.append(j)

print("Yes" if is_escaped else "No")
