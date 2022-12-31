import re
s = input()
s = re.sub('6{10,}', '27', s)
s = re.sub('6{4,9}', '9', s)
print(s)