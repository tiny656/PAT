import heapq


def build_wpl(freq):
    pq = list(freq.values())
    heapq.heapify(pq)
    wpl = 0
    while len(pq) > 1:
        a = heapq.heappop(pq)
        b = heapq.heappop(pq)
        wpl += a + b
        heapq.heappush(pq, a + b)
    return wpl


def is_prefix_free(codes):
    sorted_codes = sorted(codes.values())
    for i in range(len(sorted_codes) - 1):
        if sorted_codes[i + 1].startswith(sorted_codes[i]):
            return False
    return True


n = int(input())
freq = {}
data = input().split()
for i in range(0, len(data), 2):
    freq[data[i]] = int(data[i + 1])

WPL_min = build_wpl(freq)

m = int(input())
for _ in range(m):
    codes = {}
    ok = True
    cur_wpl = 0
    for _ in range(n):
        c, code = input().split()
        codes[c] = code
        cur_wpl += len(code) * freq.get(c, 0)

    # condition 1：all characters are present
    if len(codes) != n:
        ok = False
    # condition 2：WPL is minimum
    if cur_wpl != WPL_min:
        ok = False
    # condition 3：prefix-free
    if ok and not is_prefix_free(codes):
        ok = False
    print("Yes" if ok else "No")
