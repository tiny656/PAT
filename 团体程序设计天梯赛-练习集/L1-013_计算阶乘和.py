n = int(input())

r = 0;
b = 1
for i in range(1, n+1, 1):
    b *= i
    r += b
print(r)