n = int(input())
r = 1
if n < 0: r *= 1.5
if n % 2 == 0: r *= 2
s = list(str(n))
size = len(s)-1 if s[0] == '-' else len(s)
r *= s.count('2') / size
print("{:.2%}".format(r))