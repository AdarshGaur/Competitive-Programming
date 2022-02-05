
# t = int(input())
for _ in range(int(input())):
	n, l, r, k = map(int, input().split())
	lis = list(map(int, input().split()))
	lis.sort()
	cnt = 0
	for i in lis:
		if i > k:
			break
		if l<=i and i<=r:
			k -= i
			cnt += 1
	print(cnt)
