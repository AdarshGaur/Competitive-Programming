for _ in range(int(input())):
	n = int(input())
	a = list(map(str,input().split()))
	# print(a)
	# print(len(a))
	ans = ''
	last = '?'
	for e in a:
		if e[0] != last:
			ans += e[0]
		ans += e[1]
		last = e[1]
	while len(ans)!= n:
		ans += 'a'
	print(ans)