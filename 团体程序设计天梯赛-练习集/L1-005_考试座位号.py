n = int(input())
table = {}
for i in range(n):
    no, testSeat, officialSeat = map(int, input().split())
    table[testSeat] = (no, officialSeat)
input()
m = map(int, input().split())
for t in m:
    print("{} {}".format(table[t][0], table[t][1]))