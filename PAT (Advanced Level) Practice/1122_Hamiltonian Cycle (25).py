#coding: utf-8
# 1. cycle长度等于n+1
# 2. cycle首尾相同
# 3. cycle元素不重复且长度等于n
# 4. cycle前后元素连通

def is_hamicycle(cycle, adj_list):
    if len(cycle) != n+1: return False
    if cycle[0] != cycle[-1]: return False
    if len(set(cycle)) != n: return False 
    for i in xrange(len(cycle)-1):
        if cycle[i+1] not in adj_list[cycle[i]]:
            return False
    return True   

n, m = map(int, raw_input().split())
adj_list = [[] for i in xrange(n+1)]
for i in xrange(m):
    p, q = map(int, raw_input().split())
    adj_list[p].append(q)
    adj_list[q].append(p)


k = int(raw_input())
for i in xrange(k):
    cycle = map(int, raw_input().split()[1:])
    print 'YES' if is_hamicycle(cycle, adj_list) else 'NO'
