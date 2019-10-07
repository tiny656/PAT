def Insert(heap, val):
    heap.append(val)
    pos = len(heap)-1
    while pos/2 >= 1 and heap[pos/2] > heap[pos]:
        heap[pos/2], heap[pos] = heap[pos], heap[pos/2]
        pos = pos/2

def PrintPath(heap, i):
    ans = []
    while i >= 1:
        ans.append(heap[i])
        i /= 2
    print ' '.join(map(str, ans))


n, m = map(int, raw_input().split())
vals = map(int, raw_input().split())
heap = [None]
for v in vals:
    Insert(heap, v)
q = map(int, raw_input().split())
for i in q:
    PrintPath(heap, i)