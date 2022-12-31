s = input()
if len(s) == 4:
    if int(s[:2]) < 22:
        print("20%s-%s" % (s[0:2], s[2:4]))
    else:
        print("19%s-%s" % (s[0:2], s[2:4]))
else:
    print("%s-%s" % (s[0:4], s[4:6]))