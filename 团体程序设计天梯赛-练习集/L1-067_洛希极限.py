v, b, c = input().split()
v, c = float(v), float(c)

roche = v * (2.455 if b == '0' else 1.26)
print("%.2f %s" % (roche, 'T_T' if roche > c else '^_^'))