n = int(input())
teams = list(map(int, input().split()))

total = sum(teams)*10
seats = {}
prevTeamId, teamId = -1, 0
seatId = 0
while total > 0:
    if teamId not in seats:
        seats[teamId] = []
    if len(seats[teamId]) != teams[teamId]*10:
        total -= 1
        if prevTeamId != teamId:
            seatId += 1
            seats[teamId].append(seatId)
        else:
            seatId += 2
            seats[teamId].append(seatId)

        prevTeamId = teamId
    teamId += 1
    teamId %= n
    
for index, v in enumerate(teams):
    print("#%d" % (index+1))
    for i in range(v):
        print(" ".join(map(str, seats[index][i*10:(i+1)*10])))