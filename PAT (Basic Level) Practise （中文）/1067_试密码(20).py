#coding: utf-8

pwd, n = raw_input().split()
n = int(n)
while True:
    inp = raw_input()
    if inp == '#':
        break
    else:
        if inp == pwd:
            print 'Welcome in'
            break
        else:
            print 'Wrong password: %s' % inp
            n -= 1
            if n == 0:
                print 'Account locked'
                break

