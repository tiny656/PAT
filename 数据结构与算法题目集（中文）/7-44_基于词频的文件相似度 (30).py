import re

def GetContent():
    result = []
    while True:
        s = raw_input()
        if s.strip() == '#':
            return '\n'.join(result)
        else:
            result.append(s)

n = int(raw_input())
fileSet = [None] * n
for i in range(n):
    content = GetContent().lower()
    # regrex find all words only contain alphabet
    words = re.findall(r'([a-z]{3,})', content, re.S)
    fileSet[i] = set()
    for word in words:
        fileSet[i].add(word if len(word) <= 10 else word[:10] )

m = int(raw_input())
for i in range(m):
    a, b = map(int, raw_input().split())
    union = fileSet[a-1] | fileSet[b-1]
    intersection = fileSet[a-1] & fileSet[b-1]
    rate = len(intersection) / float(len(union)) * 100.
    print '%.1f%%' % rate

'''
3
Aaa Bbb Ccc
#
Bbb Ccc Ddd
#
Aaa2 ccc Eee
is at Ddd@Fff
#
2
1 2
1 3
'''