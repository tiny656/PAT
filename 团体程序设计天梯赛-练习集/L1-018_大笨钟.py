s = input()
h,m = map(int, s.split(":"))

if 0 <= h*24 + m <= 12 *24:
    print("Only {}.  Too early to Dang.".format(s))
else:
    count = h - 12
    if m > 0: count += 1
    print("".join(["Dang"]*count))
