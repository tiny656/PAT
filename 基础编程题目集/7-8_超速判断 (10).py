speed = int(raw_input())
result = 'OK' if speed <= 60 else 'Speeding'
print 'Speed: %d - %s' % (speed, result)