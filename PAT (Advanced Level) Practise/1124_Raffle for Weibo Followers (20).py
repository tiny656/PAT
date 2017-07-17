#coding: utf-8

def solve(m, n, s, forward):
	if s > m:
		print 'Keep going...'
		return

	win = set([forward[s-1]])
	print forward[s-1]
	cur, tar = s-1, s+n
	while True:
		if cur >= len(forward): break
		if cur == tar-1:
			if forward[tar-1] not in win:
				print forward[tar-1]
				win.add(forward[tar-1])
				tar = tar+n
			else: tar = tar+1
		cur += 1

m, n, s = map(int, raw_input().split())
forward = [raw_input() for i in xrange(m)]
solve(m,n,s,forward)
