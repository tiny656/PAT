#coding: utf-8
# python 大法好
nums = map(int, raw_input().split()[1:])
print sum(set([nums[i]*10+nums[j] for i in xrange(len(nums)) for j in xrange(len(nums)) if i!=j ]))
