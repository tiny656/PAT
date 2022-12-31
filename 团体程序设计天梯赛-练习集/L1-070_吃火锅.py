is_first = True
first_index = -1
huoguo_count = 0
message_count = 0
while True:
    message = input()
    if message == '.': break

    message_count += 1
    if 'chi1 huo3 guo1' in message:
        huoguo_count += 1
        if is_first:
            first_index = message_count
            is_first = False

print(message_count)
if huoguo_count > 0:
    print(first_index, huoguo_count)
else:
    print('-_-#')