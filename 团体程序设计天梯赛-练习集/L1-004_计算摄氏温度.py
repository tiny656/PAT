def GetCelsius(f):
    return int(5. * (f - 32.) / 9.)

f = int(input())
print("Celsius = {}".format(GetCelsius(f)))
