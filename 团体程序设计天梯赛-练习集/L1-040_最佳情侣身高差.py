n = int(input())
for i in range(n):
    g, h = input().split()
    h = float(h)
    if g == "F":
        print("%.2f" % (h*1.09))
    else:
        print("%.2f" % (h/1.09))
