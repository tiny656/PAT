x = int(input())

target = 0
count = 1
while True:
    target = target * 10 + 1
    if target % x == 0:
        print(target//x, count)
        break
    count += 1
