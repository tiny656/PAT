#coding: utf-8

def isPalindromicNumber(num):
    num = str(num)
    splitPos = len(num)/2
    return num[:splitPos] == num[::-1][:splitPos]

A = raw_input()
if isPalindromicNumber(int(A)):
    print '%s is a palindromic number.' % A
else:
    times = 0
    while True:
        B = A[::-1]
        C = int(A) + int(B)
        print '%d + %d = %d' % (int(A), int(B), C)
        if isPalindromicNumber(C):
            print '%d is a palindromic number.' % C
            break
        else:
            times += 1
            if times >= 10:
                print 'Not found in 10 iterations.'
                break
        A = str(C)