n = int(input())
s = list(map(lambda x: 1/float(x), input().split()))
print('%.2f' % (1/sum(s)*n))