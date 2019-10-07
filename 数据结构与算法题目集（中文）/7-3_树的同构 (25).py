class TreeNode:
    def __init__(self):
        self.left = None
        self.right = None
        self.data = None

# 1. both nodes are None
# 2. nodes are not None, A.data equals B.Data, and [IsIsomorphism(A.left, B.left) && IsIsomorphism(A.right, B.right) or IsIsomorphism(A.left, B.right) && IsIsomorphism(A.right, B.left)]
def IsIsomorphism(A, B):
    return (A is None and B is None) or \
           (A is not None and B is not None and A.data == B.data and ( \
                (IsIsomorphism(A.left, B.left) and IsIsomorphism(A.right, B.right)) or \
                (IsIsomorphism(A.left, B.right) and IsIsomorphism(A.right, B.left)) \
           ))

n = int(raw_input())
A = [TreeNode() for i in xrange(n)]
elems = [i for i in xrange(n)]
for i in xrange(n):
    d, l, r = raw_input().split()
    A[i].data = d
    if l != '-':
        elems.append(int(l))
        A[i].left = A[int(l)]
    if r != '-':
        elems.append(int(r))
        A[i].right = A[int(r)]
root_A = None if not elems else reduce(lambda x, y: x^y, elems)

n = int(raw_input())
B = [TreeNode() for i in xrange(n)]
elems = [i for i in xrange(n)]
for i in xrange(n):
    d, l, r = raw_input().split()
    B[i].data = d
    if l != '-':
        elems.append(int(l))
        B[i].left = B[int(l)]
    if r != '-':
        elems.append(int(r))
        B[i].right = B[int(r)]
root_B = None if not elems else reduce(lambda x, y: x^y, elems)

if (root_A is None and root_B is None) or IsIsomorphism(A[root_A], B[root_B]):
    print 'Yes'
else:
    print 'No'