# SEGMENT_TREE_BJ_10868.py
import sys
import math

def query(node, start, end, left, right):
	if left > end or right < start:
		return sys.maxsize
	if left <= start and right >= end:
		return tree[node]
	mid = (start + end) // 2
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right))

def init(node, start, end):
	if start == end:
		tree[node] = arr[start]
		return tree[node]
	mid = (start + end) // 2
	tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end))
	return tree[node]

arr, tree = [], []

if __name__=="__main__":
	N, M = [int(x) for x in sys.stdin.readline().split()]
	h = math.ceil(math.log2(N))
	treesize = 2 ** (h + 1)
	tree = [0 for _ in range(0, treesize)]
	for i in range(0, N):
		arr.append(int(sys.stdin.readline()))
	init(1, 0, N - 1)
	for i in range(0, M):
		a, b = [int(x) for x in sys.stdin.readline().split()]
		print(query(1, 0, N - 1, a - 1, b - 1))

# 10 4
# 75
# 30
# 100
# 38
# 50
# 51
# 52
# 20
# 81
# 5
# 1 10
# 3 5
# 6 9
# 8 10