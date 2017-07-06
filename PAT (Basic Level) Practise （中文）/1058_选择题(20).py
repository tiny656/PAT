#coding: utf-8
def process_question(sol_inp):
    return (sol_inp[0], ''.join(sorted(sol_inp[3:])))

student_num, question_num = map(int, raw_input().split())
stu_scores, wrong_stats, max_wrong_nums = [0]*student_num, [0]*question_num, 0

solutions = [process_question(raw_input().split()) for i in xrange(question_num)]

for i in xrange(student_num):
    stu_answers = raw_input()[1:-1].split(') (')
    for idx, ans in enumerate(stu_answers):
        if ''.join(sorted(ans.split(' ')[1:])) == solutions[idx][1]:
            stu_scores[i] += int(solutions[idx][0])
        else:
            wrong_stats[idx] += 1
            max_wrong_nums = max(wrong_stats[idx], max_wrong_nums)

for i in xrange(student_num):
    print stu_scores[i]

if max_wrong_nums == 0:
    print 'Too simple'
else:
    output = '%d' % max_wrong_nums
    for idx, wrong_nums in enumerate(wrong_stats):
        if wrong_nums == max_wrong_nums:
            output += ' %d' % (idx+1)
    print output