#coding: utf-8

# 树的先序和后序构造中序，遍历分左右子树可能存在多解

def build(preLeft, preRight, postLeft, postRight):
    global max_find_count
    root = preOrder[preLeft]
    preLeft += 1
    postRight -= 1
    size = preRight - preLeft + 1
    pos, find_count = -1, 0

    for i in xrange(size+1):
        preLeftList = preOrder[preLeft : preLeft+i]
        preRightList = preOrder[preLeft+i : preRight+1]
        postLeftList = postOrder[postLeft : postLeft+i]
        postRightList = postOrder[postLeft+i : postRight+1]

        if ((len(preLeftList) == 0 and len(postLeftList) == 0) \
                or (sorted(preLeftList) == sorted(postLeftList) and preLeftList[0] == postLeftList[-1])) \
            and ((len(preRightList) == 0 and len(postRightList) == 0) \
                or (sorted(preRightList) == sorted(postRightList) and preRightList[0] == postRightList[-1])):
            pos = i
            find_count += 1
            max_find_count = max(max_find_count, find_count)
    if pos > 0: 
        build(preLeft, preLeft+pos-1, postLeft, postLeft+pos-1)
    ans.append(root)
    if 0 <= pos < size: 
        build(preLeft+pos, preRight, postLeft+pos, postRight)

n = int(raw_input())
preOrder = map(int, raw_input().split())
postOrder = map(int, raw_input().split())
max_find_count, ans = 0, []
build(0, n-1, 0, n-1)
print 'Yes' if max_find_count == 1 else 'No'
print ' '.join(map(str, ans))


