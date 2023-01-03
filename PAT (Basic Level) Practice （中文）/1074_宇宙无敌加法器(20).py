#coding: utf-8

# 模拟加法，注意0的边界值判断

carry_tmpl = map(int, list(raw_input()))
carry_tmpl.reverse()
a = map(int, list(raw_input()))
b = map(int, list(raw_input()))
a.reverse()
b.reverse()
c, carry = [], 0

cnt = max(len(a), len(b), len(carry_tmpl))
a.extend([0]*(cnt-len(a)+1))
b.extend([0]*(cnt-len(b)+1))

for i in xrange(max(len(a), len(b))):
    mod = 10 if i >= len(carry_tmpl) or carry_tmpl[i] == 0 else carry_tmpl[i]
    bit = (a[i] + b[i] + carry) % mod
    carry = (a[i] + b[i] + carry) / mod
    c.append(bit)

result = ''.join(map(str, c)).rstrip('0')[::-1]
if result == '':
    print 0
else:
    print result
