pinyin = ['ling', 'yi', 'er', 'san', 'si', 'wu', 'liu', 'qi', 'ba', 'jiu']

def get_number(s):
	if 'sqrt' in s:
		n = int(s[4:])
		return int(n ** 0.5)
	
	if s in pinyin:
		return pinyin.index(s)
	
	if '^' in s:
		n, m = map(int, s.split('^'))
		return int(n ** m)
	
	return int(eval(s))

phone = []
for i in range(11):
	s = input()
	phone.append(get_number(s))
print(''.join(map(str, phone)))