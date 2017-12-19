#coding: utf-8

class Item(object):
    def __init__(self, alpha):
        self.alpha = alpha
        self.times = 1

def compress(s):
    sential = ''
    curItem = None
    notes = []
    for ch in s:
        if ch == sential:
            curItem.times += 1
        else:
            if curItem: notes.append(curItem)
            curItem = Item(ch)
            sential = ch
    if curItem: notes.append(curItem)
    ans = ''
    for item in notes:
        if not item.times == 1:
            ans += str(item.times)
        ans += item.alpha
    print ans

def uncompress(s):
    idx = 0
    times = 0
    ans = ''
    while idx < len(s):
        if s[idx].isdigit():
            times = times*10 + int(s[idx])
        else:
            ans += s[idx] * (times if times != 0 else 1)
            times = 0
        idx += 1
    print ans

mode = raw_input()
inp = raw_input()
if mode == 'C':     compress(inp)
elif mode == 'D':   uncompress(inp)