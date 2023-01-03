n = int(input())
alumnis = set()
for i in range(n):
    alumnis.add(input())

alumni_count = 0
elder = [None, 0] # 0: id, 1: alumni(1) or not(0)
m = int(input())
for i in range(m):
    person = input()
    if person in alumnis:
        alumni_count += 1
        if elder[0] is None or elder[1] == 0 or (elder[1] == 1 and person[6:14] < elder[0][6:14]):
            elder = (person, 1)
    else:
        if elder[0] is None or (elder[1] == 0 and person[6:14] < elder[0][6:14]):
            elder = (person, 0)
    
print(alumni_count)
print(elder[0])