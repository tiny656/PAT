from fractions import Fraction

n = int(input())
nums = input().split(' ')
s = Fraction(0, 1)
for num in nums:
    a, b = map(int, num.split('/'))
    s += Fraction(a, b)

if s.numerator > s.denominator:
    v = s.numerator // s.denominator
    s -= Fraction(v, 1)
    ans = str(v)
    if s != 0:
        ans += " " + str(s)
    print(ans)
else:
    print(s)
