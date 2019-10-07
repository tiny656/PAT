class Node:
    def __init__(self):
        self.left = None
        self.right = None
        self.data = None

def BuildTree(nodes):
    root = None
    for val in nodes:
        root = Insert(root, val)
    return root

def Insert(node, value):
    if node is None:
        node = Node()
        node.data = value
    if node.data > value:
        node.right = Insert(node.right, value)
    if node.data < value:
        node.left = Insert(node.left, value)
    return node

def IsSameBST(t, s):
    return (t is None and s is None) or \
       (t is not None and s is not None and t.data == s.data and IsSameBST(t.left, s.left) and IsSameBST(t.right, s.right))

while True:
    inp = raw_input().split()
    if len(inp) == 1 and inp[0] == '0': break

    n, l = map(int, inp)
    t = BuildTree(map(int, raw_input().split()))

    for i in xrange(l):
        s = BuildTree(map(int, raw_input().split()))
        print 'Yes' if IsSameBST(t, s) else 'No'