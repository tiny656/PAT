t = int(raw_input())
rabbit, turtle = 0, 0
rabbit_run = 0
rabbit_rest = 0

while t != 0:
    turtle += 3
    if not rabbit_rest:
        rabbit += 9
        rabbit_run += 1
    else:
        rabbit_rest -= 1

    if rabbit_run == 10:
        if rabbit > turtle:
            rabbit_rest = 30
        rabbit_run = 0

    t -= 1

if turtle > rabbit:
    print '@_@', turtle
elif turtle < rabbit:
    print '^_^', rabbit
else:
    print '-_-', turtle
