b, e =map(int, input().split())
for i, elem in enumerate(range(b, e+1, 1)):
    print(f'{elem:>5}', end='')
    if (i != 0 and i % 5 == 4 and elem != e):
        print("")
print('\nSum = {}'.format(sum(range(b, e+1, 1))))
