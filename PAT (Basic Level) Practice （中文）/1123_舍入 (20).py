from decimal import *


def round_number(method, number, precision):
    context = getcontext()
    context.prec = 300  # 精度位数一定要大
    if method == "1":
        context.rounding = ROUND_HALF_UP
    elif method == "2":
        context.rounding = ROUND_DOWN
    elif method == "3":
        context.rounding = ROUND_HALF_EVEN

    d = Decimal(number).quantize(Decimal("0." + "0" * precision))
    if d == 0:
        d = abs(d)
    ans = str(d)
    if ans[0] == "+":
        ans = ans[1:]
    return ans


n, d = map(int, input().split())
for i in range(n):
    op, num = input().split()
    print(round_number(op, num, d))
