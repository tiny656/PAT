p = {
    "-": "fu",
    "0": "ling",
    "1": "yi",
    "2": "er",
    "3": "san",
    "4": "si",
    "5": "wu",
    "6": "liu",
    "7": "qi",
    "8": "ba",
    "9": "jiu"
}


n = map(lambda x: p[x], list(input()))
print(" ".join(n))
