n = int(raw_input())
b = bin(n)[2:]
b = '0'* (8 - len(b)) + b
print int(b[:4], 2) * 10 + int(b[4:], 2)
