n = input()
bits = list(n)
count = [0]*10
for b in bits:
    count[ord(b)-ord('0')] += 1
for i in range(0, 10, 1):
    if count[i] != 0:
        print("{}:{}".format(i, count[i]))
