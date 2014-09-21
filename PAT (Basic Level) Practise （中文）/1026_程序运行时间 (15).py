c1, c2 = map(int, raw_input().split(' '))
t = round((c2 - c1) / 100.0)

s = t % 60
m = t / 60 % 60
h = t / 60 / 60
print "%02d:%02d:%02d" % (h, m, s)