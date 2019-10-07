def PrintAns(C):
    for idx in list(C.keys()): # make sure not changes elements for loop item
        if C[idx] == 0:
            del C[idx]
    if not C:
        print '0 0'
    else:
        result = []
        for idx in sorted(C.keys(), reverse=True):
            result.append(C[idx])
            result.append(idx)
        print ' '.join(map(str, result))

A, B, C = {}, {}, {}

inp = map(int, raw_input().split()[1:])
for i in xrange(0, len(inp), 2):
    A[inp[i+1]] = inp[i]

inp = map(int, raw_input().split()[1:])
for i in xrange(0, len(inp), 2):
    B[inp[i+1]] = inp[i]

for A_idx, A_val in A.iteritems():
    for B_idx, B_val in B.iteritems():
        C[A_idx+B_idx] = C.setdefault(A_idx+B_idx, 0) + A_val*B_val
PrintAns(C)

C.clear()
for A_idx, A_val in A.iteritems():
    C[A_idx] = C.setdefault(A_idx, 0) + A_val
for B_idx, B_val in B.iteritems():
    C[B_idx] = C.setdefault(B_idx, 0) + B_val
PrintAns(C)