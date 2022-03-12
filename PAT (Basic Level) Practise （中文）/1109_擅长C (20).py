import string
alphabet = {}
for ch in string.ascii_uppercase:
    alphabet[ch] = []
    for i in range(7):
        alphabet[ch].append(input())

word = ""
words = []
sentence = input()
for idx, ch in enumerate(sentence):
    if ch in string.ascii_uppercase:
        word += ch
    else:
        if word:
            words.append(word)
            word = ""

if word:
    words.append(word)

is_first_word = True
for w in words:
    # deal with blank line
    if is_first_word:
        is_first_word = False
    else:
        print()

    # row scan from top to bottom
    # in each row, characters of word scan
    # record the charcacter pattern of word in current row. 
    for i in range(7):
        ans = []
        for ch in w:
            ans.append(alphabet[ch][i])
        print(" ".join(ans))