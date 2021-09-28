# RECURSIVE_BJ_9184.py
import sys

def w(a, b, c):
	if a <= 0 or b <= 0 or c <= 0:
		return 1
	if a > 20 or b > 20 or c > 20:
		return w(20, 20, 20)
	if dp[a][b][c] != -1:
		return dp[a][b][c]
	if a < b and b < c:
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
		return dp[a][b][c]
	dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)
	return dp[a][b][c]

dp = []

if __name__=="__main__":
	dp = [[[-1 for _ in range(0, 21)] for _ in range(0, 21)] for _ in range(0, 21)]

	while True:
		a, b, c = [int(x) for x in sys.stdin.readline().split()]
		if a == -1 and b == -1 and c == -1:
			break
		print("w(%s, %s, %s) = %s" %(a, b, c, w(a, b, c)))


