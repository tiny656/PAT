def is_lucky(num_str):
    result, val = True, 0
    for i in range(0, len(num_str)):
        val = val * 10 + int(num_str[i])
        result &= val % (i + 1) == 0
    return result


input()
num_str_arr = input().split()
for num_str in num_str_arr:
    print("Yes" if is_lucky(num_str) else "No")
