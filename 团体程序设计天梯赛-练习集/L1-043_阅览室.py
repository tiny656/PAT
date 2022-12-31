n = int(input())

book = {}
cnt, readingTime = 0, 0

while n > 0:
    bookID, key, time = input().split()
    bookID = int(bookID)
    h, m = time.split(':')
    timestamp = int(h) * 60 + int(m)

    if bookID == 0:
        n -= 1
        print(cnt, "{:.0f}".format(0 if cnt == 0 else readingTime/cnt))
        cnt, readingTime = 0, 0
        book.clear()
        continue

    if key == 'S':
        book[bookID] = timestamp

    if key == 'E':
        if bookID in book:
            cnt += 1
            readingTime += timestamp - book[bookID]
            del book[bookID]