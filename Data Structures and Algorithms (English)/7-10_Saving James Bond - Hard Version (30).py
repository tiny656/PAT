import math
from collections import deque


def dist(a, b):
    return math.hypot(a[0] - b[0], a[1] - b[1])


def can_escape(croc, D):
    """判断鳄鱼 croc=(x,y) 能否一步跳到岸"""
    x, y = croc
    return 50 - max(abs(x), abs(y)) <= D


n, d = list(map(int, input().split()))
crocs = [tuple(map(int, input().split())) for _ in range(n)]

# 直接从岛跳到岸
if d >= 42.5:  # 50 - 7.5
    print(1)
else:
    # 找第一跳可达的鳄鱼, 并按距离排序
    first = [i for i, (x, y) in enumerate(crocs) if dist((0, 0), (x, y)) <= d + 7.5]
    first.sort(key=lambda i: dist((0, 0), crocs[i]))

    queue = deque(first)
    visited = [False] * n
    pre = [-1] * n  # 记录前驱，便于回溯路径

    for i in first:
        visited[i] = True
        pre[i] = -2

    escape_idx = -1
    while queue:
        i = queue.popleft()
        if can_escape(crocs[i], d):  # 找到首条满足要求的最短路径
            escape_idx = i
            break
        for j in range(n):
            if not visited[j] and dist(crocs[i], crocs[j]) <= d:
                visited[j] = True
                pre[j] = i
                queue.append(j)

    if escape_idx == -1:
        print(0)
    else:
        path = []
        p = escape_idx
        while p != -2:
            path.append(crocs[p])
            p = pre[p]
        path.reverse()

        jumps = len(path) + 1  # +1 为最后一跳到岸
        print(jumps)
        for x, y in path:
            print(f"{x} {y}")
