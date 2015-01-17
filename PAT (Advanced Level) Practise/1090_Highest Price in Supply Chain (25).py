# Pyton 超时
n, p, r = map(float, raw_input().split())
relation = map(int, raw_input().split())
adjList = {}
root = -1
for idx, val in enumerate(relation):
    adjList.setdefault(val, []).append(idx)
    if val == -1:
        root = idx

max_dep = 0
max_dep_cnt = 0

q = []
q.append((root, 0))
while len(q) != 0:
    cur, dep = q.pop(0)
    if dep > max_dep:
        max_dep, max_dep_cnt = dep, 1
    elif dep == max_dep:
        max_dep_cnt += 1
    if adjList.get(cur):
        for v in adjList.get(cur):
            q.append((v, dep+1))

print "%.2f %d" % (p*(1+r/100)**max_dep, max_dep_cnt)

