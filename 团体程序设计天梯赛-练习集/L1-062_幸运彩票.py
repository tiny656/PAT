n = int(input())
for i in range(n):
    t = list(map(int, list(input())))
    if sum(t[:3]) == sum(t[-3:]):
        print("You are lucky!")
    else:
        print("Wish you good luck.")