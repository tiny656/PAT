#coding: utf-8

n, m = map(int, raw_input().split())
forbid_list = set(raw_input().split())
black_user_list = []
black_user_thing = {}
forbid_cnt = 0
for i in xrange(n):
    line = raw_input().split()
    user, things = line[0], line[2:]
    needRecord = False
    for t in things:
        if t in forbid_list:
            forbid_cnt += 1
            needRecord = True
            black_user_thing.setdefault(user, []).append(t)
    if needRecord:
        black_user_list.append(user)
for u in black_user_list:
    s = u + ':'
    for t in black_user_thing[u]:
        s += ' ' + t
    print s
print len(black_user_list), forbid_cnt
