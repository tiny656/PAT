year, hour = map(int, raw_input().split())
base = 30 if year < 5 else 50
salary = base * (max(hour - 40, 0) * 1.5 + min(40, hour))
print '%d.00' % salary
