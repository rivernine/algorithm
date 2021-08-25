# SEGMENT_TREE_BJ_2357.py
import sys
import math

def query(node, start, end, left, right):
  if left > end or right < start:
    return [sys.maxsize, 0]
  if left <= start and right >= end:
    return tree[node]
  mid = (start + end) // 2

  lnode = query(node * 2, start, mid, left, right)
  rnode = query(node * 2 + 1, mid + 1, end, left, right)
  return [min(lnode[0], rnode[0]), max(lnode[1], rnode[1])]

def init(node, start, end):
  if start == end:
    tree[node] = [arr[start], arr[start]]
    return tree[node]
  mid = (start + end) // 2

  lnode = init(node * 2, start, mid)
  rnode = init(node * 2 + 1, mid + 1, end)
  tree[node] = [min(lnode[0], rnode[0]), max(lnode[1], rnode[1])]
  return tree[node]

arr, tree = [], []

if __name__=="__main__":
  N, M = [int(x) for x in sys.stdin.readline().split()]
  for i in range(0, N):
    arr.append(int(sys.stdin.readline()))
  h = math.ceil(math.log2(N))
  tree_size = 2**(h + 1)
  tree = [[0, 0]] * tree_size
  init(1, 0, N - 1)

  for _ in range(0, M):
    a, b = [int(x) for x in sys.stdin.readline().split()]
    mn, mx = query(1, 0, N - 1, a - 1, b - 1)
    print(mn, mx)

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