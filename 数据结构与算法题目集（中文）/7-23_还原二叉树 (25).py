class TreeNode(object):
    def __init__(self):
        self.left = None
        self.right = None
        self.data = None

def BuildTree(inOrd, inBegin, inEnd,  preOrd, preBegin, preEnd):
    root = TreeNode()
    root.data = preOrd[preBegin]
    p = inOrd.index(root.data)
    leftSize = p - inBegin
    rightSize = inEnd - p
    if leftSize > 0:
        root.left = BuildTree(inOrd, inBegin, p-1, preOrd, preBegin+1, preBegin+leftSize)
    if rightSize > 0:
        root.right = BuildTree(inOrd, p+1, inEnd, preOrd, preEnd-rightSize+1, preEnd)
    return root

def GetHeight(root):
    if root is None: return 0
    leftHeight = GetHeight(root.left)
    rightHeight = GetHeight(root.right)
    return max(leftHeight, rightHeight) + 1

n = int(raw_input())
preOrd = list(raw_input().strip())
inOrd = list(raw_input().strip())
root = BuildTree(inOrd, 0, n-1, preOrd, 0, n-1)
print GetHeight(root)