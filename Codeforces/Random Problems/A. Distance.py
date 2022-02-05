for _ in range(int(input())):
	x, y = map(int, input().split())
	if (x+y)%2 == 1:
		print("-1 -1")
	else:
		dx , dy = 0 , 0
		d = int((x+y)/2)
		if d <= x:
			dx = d
			dy = 0
		else:
			dx = 0
			dy = d
		print(dx, end=' ')
		print(dy)
