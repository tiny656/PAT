#coding: utf-8
import Queue

# 后序和中序构树，层次遍历根据当前节点层次，进行正向或者反向的记录

class TreeNode(object):
    def __init__(self, data, dep):
        self.data = data
        self.left = None
        self.right = None
        self.dep = dep

def build(postLeft, postRight, inLeft, inRight, dep):
    root = None
    for pos in xrange(inLeft, inRight+1):
        if inOrderList[pos] == postOrderList[postRight]:
            root = pos
            break
    leftSize = root - inLeft
    rightSize = inRight - root
    
    node = TreeNode(postOrderList[postRight], dep)
    node.left = build(postLeft, postLeft + leftSize - 1, inLeft, root - 1, dep+1) if leftSize > 0 else None
    node.right = build(postLeft + leftSize, postRight - 1, root+1, inRight, dep+1) if rightSize > 0 else None
    return node

n = int(raw_input())
inOrderList = map(int, raw_input().split())
postOrderList = map(int, raw_input().split())
root = build(0, n-1, 0, n-1, 0)
q = Queue.Queue(maxsize=n)
q.put(root)
s, cur_dep = '', -1
result = ''
while not q.empty():
    c = q.get()
    if cur_dep != c.dep:
        if cur_dep != -1:
            result += ' ' + s.strip()
        cur_dep = c.dep
        s = ''

    if c.dep % 2 != 0:
        s += ' ' + str(c.data)
    else:
        s = str(c.data) + ' ' + s

    if c.left: q.put(c.left)
    if c.right: q.put(c.right)
if s != '':
    result += ' ' + s.strip()
print result[1:]
