s1 = list(raw_input())
s2 = list(raw_input())
ans = []
while len(s1) != 0 and len(s2) != 0:
	if s1[0] == s2[0]:
		del s1[0]
		del s2[0]
	else:
		if s1[0].isalpha():
			if s1[0].upper() not in ans: 
				ans.append(s1[0].upper())
		else:
			if s1[0] not in ans:
				ans.append(s1[0])
		del s1[0]
while len(s1):
	if s1[0].isalpha():
			if s1[0].upper() not in ans: 
				ans.append(s1[0].upper())
	else:
		if s1[0] not in ans:
			ans.append(s1[0])
	del s1[0]
print ''.join(ans)