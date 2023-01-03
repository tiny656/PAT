#coding: utf-8

import Queue
# BFS搜索路径，DFS+回溯记录路径，简单路线去中间节点

adj = {} # 邻接表
parent = {}
path_result = []
max_dep = 99999

def build_path(stop, path):
    if stop not in parent:
        if len(path) == max_dep+1:
            global path_result
            path_result.append(path[::-1])
        return

    for prev_stop, line in parent[stop]:
        path.append((prev_stop, line))
        build_path(prev_stop, path)
        path.pop()

def search(src, dst):
    global parent, max_dep, path_result
    parent = {} # 父stop列表
    path_result = []
    max_dep = 99999
    vis = set()
    q = Queue.Queue()
    q.put((src, 0)) # (节点, 路线, 深度)
    vis.add((src, 0, 0))
    while not q.empty():
        cur_stop, cur_dep = q.get()
        if cur_dep > max_dep: break
        for nxt in adj[cur_stop]:
            next_stop, line = nxt
            if cur_dep + 1 <= max_dep and (cur_stop, next_stop) not in vis:
                info = (cur_stop, line)
                val = parent.setdefault(next_stop, set([]))
                if info not in val:
                    val.add((cur_stop, line))
                if next_stop == dst:
                    max_dep = cur_dep + 1
                else:
                    q.put((next_stop, cur_dep+1))
                vis.add((cur_stop, next_stop))
                vis.add((next_stop, cur_stop))

    path = [dst]
    build_path(dst, path)
    path.pop()
    min_line = 9999
    ans = None
    for path in path_result:
        ret_path = []
        ret_path.append(path[0])
        for i in xrange(1, len(path)-1):
            if path[i][1] != path[i-1][1]:
                ret_path.append(path[i])
        if len(ret_path) < min_line:
            min_line = len(ret_path)
            ans = ret_path
    print max_dep
    for idx, (stop, line) in enumerate(ans):
        next_stop = ans[idx+1][0] if idx+1 < len(ans) else dst
        print 'Take Line#%d from %04d to %04d.' % (line, stop, next_stop)

n = int(raw_input())
for i in xrange(n):
    line = map(int, raw_input().split())
    m, stops = line[0], line[1:]
    for j in xrange(len(stops)-1):
        p, q = stops[j], stops[j+1]
        adj.setdefault(p, []).append((q, i+1))
        adj.setdefault(q, []).append((p, i+1))

k = int(raw_input())
for i in xrange(k):
    src, dst = map(int, raw_input().split())
    search(src, dst)
