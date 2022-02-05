for _ in range(int(input())):
	s = input()
	n = len(s)
	cnt = s.count('N')
	if cnt == 1:
		print("NO")
	else:
		print("YES")
