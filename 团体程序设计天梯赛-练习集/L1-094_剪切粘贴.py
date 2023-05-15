s = input()
n = int(input())
for i in range(n):
	copy_begin, copy_end, sub_begin, sub_end = input().split()
	copy_begin, copy_end = int(copy_begin), int(copy_end)
	cut = s[copy_begin-1:copy_end]
	new_s = s[:copy_begin-1] + s[copy_end:]
	insert_begin = new_s.find(sub_begin+sub_end)
	insert_end = new_s.find(sub_end, insert_begin+len(sub_begin))
	if insert_begin == -1 or insert_end == -1:
		s = new_s + cut
	else:
		s = new_s[:insert_begin+len(sub_begin)]+cut+new_s[insert_end:]
print(s)

