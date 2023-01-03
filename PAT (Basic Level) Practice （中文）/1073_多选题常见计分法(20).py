#coding: utf-8

n, m = map(int, raw_input().split())

standard_ans_list = []
for i in xrange(m):
    line = raw_input().split()
    score, select_cnt, ans = float(line[0]), int(line[1]), set(line[3:])
    standard_ans_list.append((score, select_cnt, ans))

error_list = [None] * m # index: 问题编号 value: {错误选项: 次数}
max_error_cnt = 0

for i in xrange(n):
    score = 0.
    stu_ans_list = raw_input()[1:-1].split(') (')
    for idx, item in enumerate(stu_ans_list):

        if not error_list[idx]:
            error_list[idx] = dict()

        stu_ans = set(item.split(' ')[1:])
        ans = standard_ans_list[idx][2]
        target_score = standard_ans_list[idx][0]

        if stu_ans == ans: # 完全正确
            score += target_score
        else:
            if stu_ans < ans: # 部分正确
                score += target_score / 2.
            # 记录错误选项
            for sel in stu_ans^ans:
                error_list[idx][sel] = error_list[idx].get(sel, 0) + 1
                max_error_cnt = max(max_error_cnt, error_list[idx][sel])

    print '%.1f' % score

if max_error_cnt == 0:
    print 'Too simple'
else:
    for idx, error_sel_dict in enumerate(error_list):
        for sel in sorted(error_sel_dict.iterkeys()):
            cnt = error_sel_dict[sel]
            if cnt == max_error_cnt:
                print '%d %d-%s' % (max_error_cnt, idx+1, sel)
