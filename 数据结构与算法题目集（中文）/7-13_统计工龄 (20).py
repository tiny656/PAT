n = int(raw_input())
ages = map(int, raw_input().split())
ageDict = {}
for age in ages:
    ageDict[age] = ageDict.get(age, 0) + 1
for key in sorted(ageDict.keys()):
    print '%d:%d' % (key, ageDict[key])