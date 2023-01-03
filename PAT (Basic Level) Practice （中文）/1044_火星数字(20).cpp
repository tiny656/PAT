Mars = [
["tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"],
["",     "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"]]

def convertToMars(n):
    marsNum,ret,a,b = [],"","",""
    if n is 0:
        marsNum = [0]
    while n is not 0:
        marsNum.append(n%13)
        n /= 13
    if len(marsNum) == 2:
        a = Mars[1][marsNum[1]]
        b = Mars[0][marsNum[0]]
        if b is "tret": b = ""
        ret = a + " " + b
    elif len(marsNum) == 1:
        a = Mars[0][marsNum[0]]
        ret = a
    return ret.strip();

def convertToEarth(marNum):
    num = marNum.split(" ")
    a,b,ret = 0,0,0
    if len(num) >= 2:
        a = Mars[1].index(num[0])
        b = Mars[0].index(num[1])
        ret = a * 13 + b
    elif len(num) >= 1:
        if num[0] in Mars[1]:
            a = Mars[1].index(num[0])
            ret = a*13
        else:
            a = Mars[0].index(num[0])
            ret = a
    return ret

if __name__ == '__main__':
    n = int(raw_input())
    for i in range(n):
        number = raw_input()
        if number.isdigit():
            print convertToMars(int(number))
        else:
            print convertToEarth(number)