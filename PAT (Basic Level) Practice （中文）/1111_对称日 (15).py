import datetime

def isPalindromic(s):
	return s == s[::-1]

month = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']

n = int(input())
for i in range(n):
	s = input()
	md, y = s.split(',')
	y = y.strip().zfill(4)
	m, d = md.split(' ')
	m = str(month.index(m) + 1).zfill(2)
	d = d.zfill(2)
	date = y + m + d
	print('Y' if isPalindromic(date) else 'N', end=' ')
	print(date)
