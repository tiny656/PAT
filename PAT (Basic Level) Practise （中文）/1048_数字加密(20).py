#coding: utf-8

A, B = raw_input().split()
A, B = A[::-1], B[::-1]
alphabet, ans = "0123456789JQK", ""
for i in range(max(len(B), len(A))):
    a = int(A[i]) if i<len(A) else 0
    b = int(B[i]) if i<len(B) else 0
    ans += alphabet[(a+b) % 13] if i%2==0 else alphabet[(b-a) % 10]
print ans[::-1]

