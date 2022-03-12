s = input()
count = {}
for ch in s:
    if ch in "String":
        count[ch] = count.get(ch, 0) + 1

ans = []
while sum(count.values()) != 0:
    for ch in "String":
        if count.get(ch, 0) > 0:
            ans += ch
            count[ch] -= 1

print("".join(ans))