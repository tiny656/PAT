k = int(input())
table = { 'ChuiZi': 'Bu', 'Bu': 'JianDao', 'JianDao': 'ChuiZi' }
round = 0
while True:
    style = input()
    if style == 'End': 
        break
    
    round += 1
    if round % (k+1) == 0:
        print(style)
    else:
        print(table[style])
