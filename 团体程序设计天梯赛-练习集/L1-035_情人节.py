p = []
while True:
    s = input()
    if s == ".":
        break
    else:
        p.append(s)

if len(p) < 2:
    print("Momo... No one is for you ...")
elif len(p) < 14:
    print("%s is the only one for you..." % p[1])
else:
    print("%s and %s are inviting you to dinner..." % (p[1], p[13]))
