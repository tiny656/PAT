s = input()
arr = sorted(list(set(s)), reverse=True)
p = {}
for idx, ch in enumerate(arr):
    p[ch] = str(idx)
index = []
for ch in s:
    index.append(p[ch])

print("int[] arr = new int[]{%s};" % ','.join(arr))
print("int[] index = new int[]{%s};" % ','.join(index))
