w, h = map(float, input().split())
v = w / (h * h)

print("%.1f" % v)
print("PANG" if v > 25 else "Hai Xing")