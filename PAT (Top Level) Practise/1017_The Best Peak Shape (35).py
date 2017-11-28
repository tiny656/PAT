#coding: utf-8

def upper_bound(arr, val):
	lo, hi = 0, len(arr)-1
	while lo <= hi:
		mid  = lo + (hi-lo)/2
		if arr[mid] == val: return mid
		elif arr[mid] < val: lo = mid + 1
		else: hi = mid - 1
	return lo

def LIS(arr):
	sz = len(arr)
	b = [arr[0]]
	val = [1] * sz
	for i in xrange(1, sz):
		if arr[i] > b[-1]	:
			b.append(arr[i])
			val[i] = len(b)
		else:
			pos = upper_bound(b, arr[i])
			b[pos] = arr[i]
			val[i] = pos+1
	return val

def is_desc_asc(arr):
	min_val, idx = arr[0], 0
	for idx, val in enumerate(arr):
		if min_val >= val:
			min_val = val
			pos = idx
	for i in xrange(1, pos+1):
		if arr[i] > arr[i-1]: return False
	for i in xrange(pos+1, len(arr)):
		if arr[i] < arr[i-1]: return False
	return True



n = int(raw_input())
arr = map(int, raw_input().split())
v1, v2 = LIS(arr), LIS(arr[::-1])[::-1]
if sum(v1) == n or sum(v2) == n or is_desc_asc(arr): # 1. 下降 2. 上升 3. 下降接着上升
	print 'No peak shape'
else:
	max_len, min_diff, pos = -1, 0x7fffffff, -1
	for i in xrange(n):
		if v1[i] + v2[i] > max_len:
			pos = i
			max_len = v1[i] + v2[i]
			min_diff = abs(v2[i] - v1[i])
		elif v1[i] + v2[i] == max_len and abs(v1[i] - v2[i]) < min_diff:
			min_diff = abs(v2[i] - v1[i])
			pos = i
	print max_len-1, pos+1, arr[pos]


