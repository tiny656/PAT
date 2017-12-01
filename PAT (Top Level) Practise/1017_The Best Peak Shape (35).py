#coding: utf-8
import sys

# 正向LIS+反向LIS找最大，额外加一下非peak的形状判断

def upper_bound(arr, val):
	lo, hi = 0, len(arr)-1
	while lo <= hi:
		mid  = lo + (hi-lo)/2
		if arr[mid] == val: return mid
		elif arr[mid] < val: lo = mid + 1
		else: hi = mid - 1
	return lo

def LIS(arr, reversed=False):
	sz = len(arr)
	val = [1]*sz
	b = [sys.maxint]*sz
	b[0], scope = arr[0], xrange(1, sz)
	if reversed: b[0], scope = arr[-1], xrange(sz-2, -1, -1)
	for i in scope:
		pos = upper_bound(b, arr[i])
		b[pos] = arr[i]
		val[i] = pos+1
	return val

def is_peak_shape(arr):
	_, pos = min((v, i) for i, v in enumerate(arr))
	for i in xrange(1,pos+1):
		if arr[i] > arr[i-1]: return True
	for i in xrange(pos+1, len(arr)):
		if arr[i] < arr[i-1]: return True
	return False

n = int(raw_input())
arr = map(int, raw_input().split())
v1, v2 = LIS(arr), LIS(arr, reversed=True)
if not is_peak_shape(arr): # 1. 下降 2. 上升 3. 下降接着上升
	print 'No peak shape'
else:
	max_len, min_diff, pos = -1, sys.maxint, -1
	for i in xrange(n):
		if v1[i] + v2[i] > max_len or \
			(v1[i] + v2[i] == max_len and abs(v1[i] - v2[i]) < min_diff):
			max_len = v1[i] + v2[i]
			min_diff = abs(v2[i] - v1[i])
			pos = i
	print max_len-1, pos+1, arr[pos]