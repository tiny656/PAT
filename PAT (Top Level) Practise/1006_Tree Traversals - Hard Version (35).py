#coding: utf-8
import Queue
# 基本思想：树的三种Order进行还原
# 1. 有效性的判定
# 2. 留空一个数，记得考虑这种补集元素的情况

class Node(object):
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def isValid(inArr, preArr, postArr, inLeft, inRight, preLeft, preRight, postLeft, postRight):
    # 判断in, pre, post区间不冲突(miss的数量大于等于另一个去重去掉miss后的数量)
    inCnt, preCnt, postCnt = {}, {}, {}
    for i in xrange(inLeft, inRight+1):
        inCnt[inArr[i]] = inCnt.get(inArr[i], 0) + 1
    for i in xrange(preLeft, preRight+1):
        preCnt[preArr[i]] = preCnt.get(preArr[i], 0) + 1
    for i in xrange(postLeft, postRight+1):
        postCnt[postArr[i]] = postCnt .get(postArr[i], 0) + 1
    inMiss, preMiss, postMiss = inCnt.get('-', 0), preCnt.get('-', 0), postCnt.get('-', 0)
    in_pre_size, in_post_size, pre_post_size = 0, 0, 0
    for val, cnt in inCnt.iteritems():
        in_pre_size += min(cnt, preCnt.get(val, 0))
        in_post_size += min(cnt, postCnt.get(val, 0))
    for val, cnt in preCnt.iteritems():
        pre_post_size += min(cnt, postCnt.get(val, 0))
    return inMiss >= (preRight-preLeft+1-in_pre_size-preMiss) and preMiss >= (inRight-inLeft+1-in_pre_size-inMiss) \
        and inMiss >= (postRight-postLeft+1-in_post_size-postMiss) and postMiss >= (inRight-inLeft+1-in_post_size-inMiss) \
        and preMiss >= (postRight-postLeft+1-pre_post_size-postMiss) and postMiss >= (preRight-preLeft+1-pre_post_size-preMiss)

def buildOrder(root, method, orderList):
    if method == 'pre':
        orderList.append(root.val)
        if root.left: buildOrder(root.left, method, orderList)
        if root.right: buildOrder(root.right, method, orderList)
    elif method == 'in':
        if root.left: buildOrder(root.left, method, orderList)
        orderList.append(root.val)
        if root.right: buildOrder(root.right, method, orderList)
    elif method == 'post':
        if root.left: buildOrder(root.left, method, orderList)
        if root.right: buildOrder(root.right, method, orderList)
        orderList.append(root.val)
    elif method == 'level':
        q = Queue.Queue()
        q.put(root)
        while not q.empty():
            node = q.get()
            orderList.append(node.val)
            if node.left: q.put(node.left)
            if node.right: q.put(node.right)

def displayOrder(root, method):
    orderList = []
    func = dict.fromkeys(('pre', 'in', 'post', 'level'), buildOrder)
    func[method](root, method, orderList)
    print ' '.join(orderList)

def buildTree(remain, inArr, preArr, postArr, inLeft, inRight, preLeft, preRight, postLeft, postRight):
    retNode = None
    for pos in xrange(inLeft, inRight+1):
        # root不匹配
        s = set([preArr[preLeft], inArr[pos], postArr[postRight]])
        if not ( \
            (len(s) == 1 and '-' not in s) \
            or (len(s) == 2 and '-' in s) \
            or (len(s) == 1 and '-' in s and remain != 0 and remain <= len(inArr))):
            continue

        '-' in s and s.remove('-')
        if len(s) == 0:
            node_val = str(remain)
            remain = 0
        else:
            node_val = list(s)[0]
        leftSize = pos - inLeft
        rightSize = inRight - pos
        # 检查左半边, 右半边是否一致
        if not isValid(inArr, preArr, postArr, inLeft, pos-1, preLeft+1, preLeft+leftSize, postLeft, postLeft+leftSize-1) \
            or not isValid(inArr, preArr, postArr, pos+1, inRight, preLeft+leftSize+1, preRight, postLeft+leftSize, postRight-1):
            continue

        node = Node(node_val)
        if leftSize > 0:
            node.left = buildTree(remain, inArr, preArr, postArr, inLeft, pos-1, preLeft+1, preLeft+leftSize, postLeft, postLeft+leftSize-1)
        if rightSize > 0:
            node.right = buildTree(remain, inArr, preArr, postArr, pos+1, inRight, preLeft+leftSize+1, preRight, postLeft+leftSize, postRight-1)
        if not ((leftSize > 0 and node.left is None) or (rightSize > 0 and node.right is None)): # 只取合法情况
            retNode = node
    return retNode



n = int(raw_input())
inArr = raw_input().split()
preArr = raw_input().split()
postArr = raw_input().split()

s = set(inArr) | set(preArr) | set(postArr)
'-' in s and s.remove('-')
remain = sum(range(1, n+1)) - sum(map(int, list(s)))
# 注意remain的情况
'''
3
2 1 -
1 2 -
2 - 1
'''
root =  buildTree(remain, inArr, preArr, postArr, 0, len(inArr)-1, 0, len(preArr)-1, 0, len(postArr)-1)
if root is None: print 'Impossible'
else:
    displayOrder(root, 'in')
    displayOrder(root, 'pre')
    displayOrder(root, 'post')
    displayOrder(root, 'level')
