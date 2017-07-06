#coding: utf-8
n,m = map(int, raw_input().split())
score = map(int, raw_input().split())
correct_ans = raw_input().split()

for i in xrange(n):
    stu_ans = raw_input().split()
    tot = 0
    for j in xrange(len(stu_ans)):
        if correct_ans[j] == stu_ans[j]:
            tot += score[j]
    print tot