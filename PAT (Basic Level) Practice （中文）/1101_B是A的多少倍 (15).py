a, d = input().split()
d = int(d)
b = int(a[-d:] + a[:-d])
print("%.2f" % (b/int(a)))