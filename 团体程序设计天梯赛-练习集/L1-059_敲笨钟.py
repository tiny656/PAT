n = int(input())
for i in range(n):
    poem = input()
    left, right = poem.split(',')
    if left.endswith('ong') and right.endswith('ong.'):
        print(left + ',' + ' '.join(right.split(' ')[:-3]) + ' qiao ben zhong.')
    else:
        print('Skipped')
