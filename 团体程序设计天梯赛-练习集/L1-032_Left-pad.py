n, ch = input().split()
s = input()
n = int(n)
if n < len(s):
    print(s[len(s)-n:])
else:
    print(ch * (n-len(s)) + s)
