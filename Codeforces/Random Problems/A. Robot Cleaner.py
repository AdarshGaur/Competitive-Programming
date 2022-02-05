for _ in range(int(input())):
	n, m, xr, yr, xd, yd = map(int, input().split())
	ans = 200
	if xr <= xd:
		ans = min(ans, xd-xr)
	else:
		ans = min(ans, 2*n -xr -xd)

	if yr <= yd:
		ans = min(ans, yd-yr)
	else:
		ans = min(ans, 2*m -yr -yd)

	print(ans)