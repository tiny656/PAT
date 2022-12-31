rewards = {
    6: 10000,
    7: 36,
    8: 720,
    9: 360,
    10: 80,
    11: 252,
    12: 108,
    13: 72,
    14: 54,
    15: 180,
    16: 72,
    17: 180,
    18: 119,
    19: 36,
    20: 306,
    21: 1080,
    22: 144,
    23: 1800,
    24: 3600
}

lottery = []
for _ in range(3):
    lottery.append(list(map(int, input().split())))

s = sum(lottery[0]) + sum(lottery[1]) + sum(lottery[2])

for i in range(3):
    for j in range(3):
        if lottery[i][j] == 0:
            lottery[i][j] = 45 - s

for i in range(3):
    x, y = map(int, input().split())
    print(lottery[x - 1][y - 1])

dir = int(input())
if dir <= 3:
    print(rewards[sum(lottery[dir-1])])
elif dir <= 6:
    print(rewards[lottery[0][(dir-1)%3] + lottery[1][(dir-1)%3] + lottery[2][(dir-1)%3]])
elif dir == 7:
    print(rewards[sum([lottery[i][i] for i in range(3)])])
elif dir == 8:
    print(rewards[sum([lottery[i][2-i] for i in range(3)])])