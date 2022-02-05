for _ in range(int(input())):
	b = list(map(int,input().split()))
	a1, a2, a3 = b[0], b[1], b[2]
	j = 3
	while (a1+a2+a3) != b[6]:
		a3 = b[j]
		j += 1
	print(a1, a2, a3, sep=' ')