o, h, l, c = map(float, raw_input().split())
candle, shadow = None, []
if c < o:
    candle = "BW-Solid"
elif c > o:
    candle = "R-Hollow"
else:
    candle = "R-Cross"

if l < o and l < c:
    shadow.append("Lower Shadow")

if h > o and h > c:
    shadow.append("Upper Shadow")

if shadow:
    print '%s with %s' % (candle, ' and '.join(shadow))
else:
    print candle
