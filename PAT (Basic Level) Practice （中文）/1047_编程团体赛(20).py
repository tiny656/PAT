#coding:utf-8

n = int(raw_input())
scoreCount = {}
ans = [0, 0]
for i in range(n):
    team, score = raw_input().split(' ')
    teamID = team[:team.find('-')]
    scoreCount[teamID] = scoreCount.get(teamID, 0) + int(score)
    if scoreCount[teamID] > ans[1]:
        ans[0], ans[1] = teamID, scoreCount[teamID]
print ans[0], ans[1]
