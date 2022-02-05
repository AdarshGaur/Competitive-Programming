for _ in range(int(input())):
	a = list(map(int, input().split()))
	a = sorted(a)
	if (a[0]==a[1] and a[2]%2==0) or (a[1]==a[2] and a[0]%2==0):
		print("YES")
	elif a[0]+a[1]==a[2]:
		print("YES")
	else:
		print("NO")
