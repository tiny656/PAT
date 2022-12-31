l, n = map(int, input().split())
wide = l
r = 0
while l != 0:
    r = r * 26 + 25
    l -= 1

target = r - n + 1
ans = []
while target != 0:
    ans.append(chr(ord('a') + target % 26))
    target //= 26

# add the missing 'a' at the beginning
if len(ans) < wide:
    ans += ['a'] * (wide - len(ans))
print("".join(ans[::-1]))