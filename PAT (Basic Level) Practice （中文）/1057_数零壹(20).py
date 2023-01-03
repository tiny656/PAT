#coding:utf-8

s = raw_input()
tot, has_alpha = 0, False
for x in s:
    if x.isalpha():
        tot += ord(x.lower())-ord('a')+1
        has_alpha = True
if not has_alpha: print 0, 0 # 边界情况，没有字母的时候
else:
    v = bin(tot)
    print v.count('0')-1, v.count('1')